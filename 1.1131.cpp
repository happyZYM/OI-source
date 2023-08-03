#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=500005;
int n,s; long long res;
vector<int> G[maxn],V[maxn];
int dfs(int u,int fa)
{
	int maxv=0;
	vector<int> dep;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		int w=dfs(v,u)+V[u][i];
		maxv=max(maxv,w);
		dep.push_back(w);
	}
	for(int i=0;i<dep.size();i++) res+=maxv-dep[i];
	return maxv;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&s);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		G[a].push_back(b); G[b].push_back(a);
		V[a].push_back(c); V[b].push_back(c);
	}
	dfs(s,-1);
	printf("%lld\n",res);
	return 0;
}
