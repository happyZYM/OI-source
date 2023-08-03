// luogu-judger-enable-o2
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=1e4+5;
int n,m;
vector<int> G[maxn];
int dfn[maxn],lowlink[maxn],sccno[maxn],dfs_cnt,scc_cnt;
int v[maxn],sv[maxn]; vector<int> sg[maxn];
stack<int> S;
void dfs(int u)
{
	dfn[u]=lowlink[u]=++dfs_cnt;
	S.push(u);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(!dfn[v])
		{
			dfs(v);
			lowlink[u]=min(lowlink[u],lowlink[v]);
		}
		else if(!sccno[v]) lowlink[u]=min(lowlink[u],dfn[v]);
	}
	if(lowlink[u]==dfn[u])
	{
		scc_cnt++;
		while(true)
		{
			int x=S.top(); S.pop();
			sccno[x]=scc_cnt;
			if(x==u) break;
		}
	}
}
int f[maxn]; bool vis[maxn];
int dp(int u)
{
	int &res=f[u];
	if(vis[u]) return res;
	vis[u]=true;
	res=sv[u];
	for(int i=0;i<sg[u].size();i++) res=max(res,sv[u]+dp(sg[u][i]));
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=0;i<m;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
	for(int i=1;i<=n;i++) sv[sccno[i]]+=v[i];
	for(int u=1;u<=n;u++)
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(sccno[v]!=sccno[u]) sg[sccno[u]].push_back(sccno[v]);
		}
	int res=0;
	for(int i=1;i<=scc_cnt;i++) res=max(res,dp(i));
	printf("%d\n",res);
	return 0;
}
