#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int oo=0x3f3f3f3f;
const int maxn=100005;
vector<int> G[maxn];
int n,m,f[maxn],mi[maxn],a[maxn];
void dfs(int u,int mina,int p)
{
	int flag=1; 
	mina=min(a[u],mina);
	if(mi[u]>mina) mi[u]=mina,flag=0;
	int maxx=max(f[p],a[u]-mina);
	if(f[u]<maxx) { f[u]=maxx; flag=0; }
	if(flag) return;
	for(int i=0;i<G[u].size();i++) dfs(G[u][i],mina,u);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v,md;
		scanf("%d%d%d",&u,&v,&md);
		G[u].push_back(v);
		if(md==2) G[v].push_back(u);
	}
	memset(mi,oo,sizeof(mi));
	dfs(1,oo,0);
	printf("%d\n",f[n]);
	return 0;
}
