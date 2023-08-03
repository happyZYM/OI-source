#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10005;
struct Edge { int v,w; Edge *next; };
Edge mem[maxn*2],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->next=G[u]; G[u]=ecnt++; }
int n,m,k,res,Siz,rt,cnt;
bool vis[maxn];
int f[maxn],sz[maxn],dis[maxn];
void GetRoot(int u,int fa)
{
	f[u]=0; sz[u]=1;
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(vis[v]||v==fa) continue;
		GetRoot(v,u);
		f[u]=max(f[u],sz[v]); sz[u]+=sz[v];
	}
	f[u]=max(f[u],Siz-f[u]);
	if(f[u]<f[rt]) rt=u;
}
void GetDis(int u,int fa,int d)
{
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(vis[v]||v==fa) continue;
		dis[++cnt]=d+it->w;
		GetDis(v,u,dis[cnt]);
	}
}
int GetAns(int u,int d)
{
	dis[cnt=1]=d;
	GetDis(u,0,d);
	sort(dis+1,dis+1+cnt);
	int l=1,res=0;
	while(l<cnt&&dis[l]+dis[cnt]<k) ++l;
	while(l<cnt&&k-dis[l]>=dis[l])
	{
		auto it=equal_range(dis+l+1,dis+cnt+1,k-dis[l]);
		res+=it.second-it.first;
		++l;
	}
	return res;
}
void dfs(int u)
{
	vis[u]=true; res+=GetAns(u,0);
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(vis[v]) continue;
		res-=GetAns(v,it->w);
		Siz=sz[v]; rt=0;
		GetRoot(v,u);
		dfs(v);
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	int a,b,c;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		AddEdge(a,b,c); AddEdge(b,a,c);
	}
	while(m-->0)
	{
		scanf("%d",&k);
		res=0; memset(vis,0,sizeof(vis)); Siz=n; sz[0]=1e9+7;
		dfs(1);
		puts(res?"AYE":"NAY");
	}
	return 0;
}
