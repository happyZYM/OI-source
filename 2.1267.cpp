#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1010;
vector<int> gr[maxn],nodes[maxn];
int T,n,s,k,fa[maxn];
bool vis[maxn];
void build(int u,int f,int d)
{
	fa[u]=f;
	int nc=gr[u].size();
	if(nc==1&&d>k) nodes[d].push_back(u);
	for(int i=0;i<nc;i++)
	{
		int v=gr[u][i];
		if(v!=f) build(v,u,d+1);
	}
}
int dfs(int u,int f,int d)
{
	vis[u]=true;
	int nc=gr[u].size();
	for(int i=0;i<nc;i++)
	{
		int v=gr[u][i];
		if(v!=f&&d<k) dfs(v,u,d+1);
	}
}
int cal()
{
	int res=0;
	memset(vis,0,sizeof(vis));
	for(int d=n-1;d>k;d--)
	{
		int nc=nodes[d].size();
		for(int i=0;i<nc;i++)
		{
			int u=nodes[d][i];
			if(vis[u]) continue;
			int v=u;
			for(int j=0;j<k;j++) v=fa[v];
			dfs(v,-1,0);
			res++;
		}
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d%d",&n,&s,&k);
		for(int i=1;i<=n;i++) { gr[i].clear(); nodes[i].clear(); }
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			gr[a].push_back(b);
			gr[b].push_back(a);
		}
		build(s,-1,0);
		printf("%d\n",cal());
	}
	return 0;
}
