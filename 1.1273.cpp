#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=3005;
struct Edge { int v,w; Edge *nxt; };
int n,m,a[maxn],f[maxn][maxn],t[maxn];
Edge mem[maxn],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->nxt=G[u]; G[u]=ecnt++; }
int dfs(int u)
{
	if(u>n-m)
	{
		f[u][1]=a[u];
		return 1;
	}
	int tot=0,v,sz;
	for(Edge *it=G[u];it;it=it->nxt)
	{
		v=it->v; sz=dfs(v);
		for(int i=0;i<=tot;i++) t[i]=f[u][i];
		for(int i=0;i<=tot;i++)
			for(int j=0;j<=sz;j++)
				f[u][i+j]=max(f[u][i+j],t[i]+f[v][j]-it->w);
		tot+=sz;
	}
	return tot;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-m;i++)
	{
		int tot,v,w;
		scanf("%d",&tot);
		while(tot-->0) { scanf("%d%d",&v,&w); AddEdge(i,v,w); }
	}
	for(int i=n-m+1;i<=n;i++) scanf("%d",&a[i]);
	memset(f,~0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][0]=0;
	dfs(1);
	for(int i=m;i>=0;i--) if(f[1][i]>=0) { printf("%d\n",i); return 0; }
	return 0;
}