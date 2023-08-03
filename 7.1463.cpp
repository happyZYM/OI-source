#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1505;
const int oo=0x3f3f3f3f;
int n,u,tot,v,f[maxn][2],vis[maxn][2];
vector<int> G[maxn];
int dfs(int u,int flg,int fa)
{
	int &res=f[u][flg];
	if(vis[u][flg]) return res;
	vis[u][flg]=1;
	if(flg==1)
	{
		res=0;
		for(int i=0;i<G[u].size();i++) if(G[u][i]!=fa) res+=min(dfs(G[u][i],1,u),dfs(G[u][i],0,u));
		res++;
	}
	else
	{
		res=0;
		for(int i=0;i<G[u].size();i++) if(G[u][i]!=fa) res+=dfs(G[u][i],1,u);
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
		for(int i=0;i<n;i++) G[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d:(%d)",&u,&tot);
			for(int j=0;j<tot;j++)
			{
				scanf("%d",&v);
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		memset(vis,0,sizeof(vis));
		printf("%d\n",min(dfs(0,1,-1),dfs(0,0,-1)));
	}
	return 0;
}