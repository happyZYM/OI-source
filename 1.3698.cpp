#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=105;
int n,V;
vector<int> G[maxn];
int dp[maxn][maxn],vis[maxn][maxn],size[maxn];
void dfs(int u,int fa)
{
	size[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		dfs(v,u); size[u]+=size[v];
	}
}
int f(int u,int step,int fa)
{
	int &res=dp[u][step];
	if(vis[u][step]) return res;
	vis[u][step]=true;
	res=min(size[u],1+step/2);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		for(int j=1;j<=step;j++) res=max(res,min(size[u]-size[v],1+(step-j)/2)+f(v,j-1,u));
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&V);
	for(int i=0;i<n-1;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		G[a].push_back(b); G[b].push_back(a);
	}
	dfs(0,-1);
	printf("%d\n",f(0,V,-1));
	return 0;
}
