#include<cstdio>
#include<vector>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=305;
int n,m,cnt,id[maxn],v[maxn],w[maxn],sz[maxn],f[maxn][maxn];
vector<int> G[maxn];
void dfs(int u)
{
	sz[u]=1;
	for(int i=0;i<G[u].size();i++) { dfs(G[u][i]); sz[u]+=sz[G[u][i]]; }
	id[++cnt]=u;
}
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int f; scanf("%d%d",&f,&v[i]);
		G[f].push_back(i); w[i]=1;
	}
	dfs(0);
	for(int i=1;i<=cnt;i++)
	{
		int now=id[i];
		for(int j=m;j>=0;j--)
			if(j>=w[now]) f[i][j]=max(f[i-sz[now]][j],f[i-1][j-w[now]]+v[now]);
			else f[i][j]=f[i-sz[now]][j];
	}
	printf("%d\n",f[cnt][m]);
    return 0;
}