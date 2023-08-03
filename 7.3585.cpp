#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200005;
struct Edge { int v,w; Edge *nxt; };
Edge mem[maxn*2],*G[maxn],*ecnt;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->nxt=G[u]; G[u]=ecnt++; }
int T,n,dg[maxn],d[maxn],f[maxn];
void dp(int u,int fa)
{
	d[u]=0;
	for(Edge *it=G[u];it;it=it->nxt)
	{
		int v=it->v,w=it->w;
		if(v==fa) continue;
		dp(v,u);
		if(dg[v]==1) d[u]+=w;
		else d[u]+=min(d[v],w);
	}
}
void dfs(int u,int fa)
{
	for(Edge *it=G[u];it;it=it->nxt)
	{
		int v=it->v,w=it->w;
		if(v==fa) continue;
		if(dg[u]==1) f[v]=d[v]+w;
		else f[v]=d[v]+min(f[u]-min(d[v],w),w);
		dfs(v,u);
	}
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		ecnt=mem;
		memset(dg,0,sizeof(dg)); memset(G,0,sizeof(G));
		for(int i=1;i<=n-1;i++)
		{
			int u,v,w; scanf("%d%d%d",&u,&v,&w);
			AddEdge(u,v,w); AddEdge(v,u,w);
			dg[v]++; dg[u]++;
		}
		dp(1,-1);
		f[1]=d[1];
		dfs(1,-1);
		int res=0;
		for(int i=1;i<=n;i++) res=max(res,f[i]);
		printf("%d\n",res);
	}
	return 0;
}