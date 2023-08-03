#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=16005;
int n,a[maxn],f[maxn];
vector<int> G[maxn];
void dfs(int u,int fa)
{
	f[u]=a[u];
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		dfs(v,u);
		if(f[v]>0) f[u]+=f[v];
	}
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		G[v].push_back(u);
		G[u].push_back(v);
	}
	dfs(1,-1);
	int res=f[1];
	for(int i=2;i<=n;i++) res=max(res,f[i]);
	printf("%d\n",res);
	return 0;
}