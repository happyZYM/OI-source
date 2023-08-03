#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1005;
const int maxm=10005;
struct Edge { int v; double t; Edge *next; };
int T,n,m,kase;
Edge mem[maxm*2],*G[maxn],*ecnt;
inline void AddEdge(int u,int v,double t) { ecnt->v=v; ecnt->t=t; ecnt->next=G[u]; G[u]=ecnt++; } 
bool vis[maxn]; double run[maxn];
const double eps=1e-5;
inline int sign(double x) { return fabs(x)<eps?0:(eps>0?1:-1); }
int dfs(int u,double t)
{
	vis[u]=true; run[u]=t;
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(!vis[v]) { if(dfs(v,t*it->t)) return 1; }
		else if(sign(run[v]-t*it->t)) return 1;
	}
	return 0;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d",&n,&m);
		memset(G,0,sizeof(G)); ecnt=mem;
		while(m-->0)
		{
			int u,v; double x,y; scanf("%d%d%lf%lf",&u,&v,&x,&y);
			AddEdge(u,v,y/x); AddEdge(v,u,x/y);
		}
		memset(vis,0,sizeof(vis));
		int err=0;
		for(int i=1;i<=n&&!err;i++)
			if(!vis[i])
				err|=dfs(i,1);
		printf("Case #%d: %s\n",++kase,err?"No":"Yes");
	}
	return 0;
}
