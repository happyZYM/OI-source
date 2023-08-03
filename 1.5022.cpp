#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=5005;
vector<int> G[maxn];
int n,m;
int broke[maxn][maxn],vis[maxn],cnt,out[maxn],res[maxn];
void dfs(int u)
{
	vis[u]=true; out[cnt++]=u;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(!broke[u][v]&&!vis[v]) dfs(v);
	}
}
inline bool better()
{
	if(cnt<n) return false;
	for(int i=0;i<n;i++)
		if(out[i]<res[i]) return true;
		else if(out[i]>res[i]) return false;
	return true;
}
int main()
{
#ifdef local
	freopen("testdata.in","r",stdin);
	freopen("pro.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		G[x].push_back(y); G[y].push_back(x);
	}
	for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
	dfs(1); memcpy(res,out,sizeof(res));
	if(n==m)
	{
		for(int i=1;i<=n;i++)
			for(int j=0;j<G[i].size();j++)
			{
				int v=G[i][j];
				if(v<i) continue;
				memset(vis,0,sizeof(vis)); cnt=0;
				broke[i][v]=broke[v][i]=true;
				dfs(1);
				broke[i][v]=broke[v][i]=false;
				if(better()) memcpy(res,out,sizeof(res));
			}
	}
	for(int i=0;i<n;i++) printf("%d ",res[i]); printf("\n");
	return 0;
}
