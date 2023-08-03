#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
struct Edge { int v; Edge *next; };
Edge *G[maxn],mem[maxn*2],*ecnt=mem;
void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; }
int n,m,x,y;
int low[maxn],dfn[maxn],dfs_clock;
bool iscut[maxn];
int dfs(int u,int fa)
{
	int lowu=dfn[u]=++dfs_clock,child=0;
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(!dfn[v])
		{
			++child;
			int lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>=dfn[u]) iscut[u]=true;
		}
		else if(dfn[v]<dfn[u]&&v!=fa) lowu=min(lowu,dfn[v]); 
	}
	if(fa<0&&child<=1) iscut[u]=false;
	return lowu;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	while(m-->0)
	{
		scanf("%d%d",&x,&y);
		AddEdge(x,y); AddEdge(y,x);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i,-1);
	int sum=0;
	for(int i=1;i<=n;i++) sum+=iscut[i];
	printf("%d\n",sum);
	for(int i=1;i<=n;i++) if(iscut[i]) printf("%d ",i);
	printf("\n");
	return 0;
}
