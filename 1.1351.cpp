#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=200005;
const int mod=10007;
struct Edge { int v; Edge *next; };
Edge mem[maxn*2],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; }
int n,mx,tot,a[maxn],m1[maxn],m2[maxn],sum[maxn];
void dfs(int u,int fa)
{
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(v==fa) continue;
		dfs(v,u);
		
		if(a[v]>=m1[u]) { m2[u]=m1[u]; m1[u]=a[v]; }
		else if(a[v]>=m2[u]) m2[u]=a[v];
		mx=max(mx,a[u]*m1[v]);
		
		tot=(tot+sum[u]*a[v])%mod;
		sum[u]=(sum[u]+a[v])%mod;
		tot=(tot+a[u]*sum[v])%mod;
	}
	mx=max(mx,m1[u]*m2[u]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		AddEdge(u,v); AddEdge(v,u);
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,-1);
	printf("%d %d\n",mx,tot*2%mod);
	return 0;
}
