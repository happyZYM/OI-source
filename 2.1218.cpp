#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10000+5;
const int INF=1000000000;
vector<int> G[maxn],ves;
int p[maxn],d[maxn][3];
void dfs(int u,int fa)
{
	ves.push_back(u);
	p[u]=fa;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v!=fa) dfs(v,u);
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++) G[i].clear();
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);u--;v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ves.clear();
		dfs(0,-1);
		for(int i=ves.size()-1;i>=0;i--)
		{
			int u=ves[i];
			d[u][0]=1;d[u][1]=0;
			for(int j=0;j<G[u].size();j++)
			{
				int v=G[u][j];
				if(v==p[u]) continue;
				d[u][0]+=min(d[v][0],d[v][1]);
				d[u][1]+=d[v][2];
				if(d[u][0]>INF) d[u][0]=INF;
				if(d[u][1]>INF) d[u][1]=INF;
			}
			d[u][2]=INF;
			for(int j=0;j<G[u].size();j++)
			{
				int v=G[u][j];
				if(v==p[u]) continue;
				d[u][2]=min(d[u][2],d[u][1]-d[v][2]+d[v][0]);
			}
		}
		printf("%d\n",min(d[0][0],d[0][2]));
		scanf("%d",&n);
	}
	return 0;
}
