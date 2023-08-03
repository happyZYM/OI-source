#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
const int maxmem=maxn*31;
int n,d[maxn],E[maxmem][2],cnt;
struct Edge { int v,w; Edge *nxt; };
Edge mem[maxn*2],*G[maxn],*ecnt;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->nxt=G[u]; G[u]=ecnt++; }
void dfs(int u,int fa,int val)
{
	d[u]=val;
	for(Edge *it=G[u];it;it=it->nxt) if(it->v!=fa) dfs(it->v,u,val^it->w);
}
inline void insert(int x)
{
	int p=0;
	for(int i=30;i>=0;i--)
	{
		int now=(x>>i)&1;
		if(!E[p][now]) E[p][now]=++cnt;
		p=E[p][now];
	}
}
inline int query(int x)
{
	int p=0,res=0,w=0;
	for(int i=30;i>=0;i--)
	{
		int now=(x>>i)&1;
		if(E[p][now^1]) { p=E[p][now^1]; res+=1<<i; }
		else p=E[p][now];
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		ecnt=mem; memset(G,0,sizeof(G));
		memset(E,0,sizeof(E)); cnt=0;
		for(int i=0;i<n-1;i++)
		{
			int u,v,w; scanf("%d%d%d",&u,&v,&w); u++; v++;
			AddEdge(u,v,w); AddEdge(v,u,w);
		}
		dfs(1,-1,0);
		int res=0;
		for(int i=1;i<=n;i++) insert(d[i]);
		for(int i=1;i<=n;i++) res=max(res,query(d[i]));
		printf("%d\n",res);
	}
	return 0;
}
