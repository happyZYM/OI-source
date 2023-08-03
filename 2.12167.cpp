#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=20005;
int T,n,m,in0[maxn],out0[maxn];
vector<int> G[maxn];
int dfn[maxn],lowlink[maxn],sccno[maxn],dfs_cnt,scc_cnt;
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
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=0;i<m;i++)
		{
			int u,v; scanf("%d%d",&u,&v);
			G[u].push_back(v);
		}
		dfs_cnt=0; scc_cnt=0;
		memset(sccno,0,sizeof(sccno));
		memset(dfn,0,sizeof(dfn));
		for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
		for(int i=1;i<=scc_cnt;i++) in0[i]=out0[i]=1;
		for(int u=1;u<=n;u++)
			for(int i=0;i<G[u].size();i++)
			{
				int v=G[u][i];
				if(sccno[v]!=sccno[u]) in0[sccno[v]]=out0[sccno[u]]=0;
			}
		int a=0,b=0;
		for(int i=1;i<=scc_cnt;i++) a+=in0[i],b+=out0[i];
		int ans=max(a,b);
		if(scc_cnt==1) ans=0;
		printf("%d\n",ans);
	}
	return 0;
}
