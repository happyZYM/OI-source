//http://acm.hdu.edu.cn/showproblem.php?pid=2196
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=10005;
int n,d[maxn],f[maxn],val[maxn][2];
vector<int> G[maxn],E[maxn];
void dfs1(int u)
{
	for(int i=0;i<G[u].size();i++)
	{
		dfs1(G[u][i]);
		d[u]=max(d[u],E[u][i]+d[G[u][i]]);
	}
}
void dfs2(int u,int fa,int w)
{
	f[u]=w+f[fa];
	if(d[u]+w==val[fa][0]) f[u]=max(f[u],w+val[fa][1]);
	else f[u]=max(f[u],w+val[fa][0]);
	for(int i=0;i<G[u].size();i++)
	{
		int t=d[G[u][i]]+E[u][i];
		if(t>val[u][0]) { val[u][1]=val[u][0]; val[u][0]=t; }
		else val[u][1]=max(val[u][1],t);
	}
	for(int i=0;i<G[u].size();i++) dfs2(G[u][i],u,E[u][i]);
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++) { G[i].clear(); E[i].clear(); }
		memset(d,0,sizeof(d));
		memset(f,0,sizeof(f));
		memset(val,0,sizeof(val));
		for(int i=2;i<=n;i++)
		{
			int v,w; scanf("%d%d",&v,&w);
			// G[i].push_back(v);
			G[v].push_back(i);
			E[v].push_back(w);
		}
		dfs1(1);
		dfs2(1,0,0);
		for(int i=1;i<=n;i++) printf("%d\n",max(f[i],d[i]));
	}
	return 0;
}