#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=6005;
vector<int> G[maxn];
int f[maxn][2],v[maxn],h[maxn],n;
void dp(int u)
{
	f[u][0]=0;
	f[u][1]=h[u];
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		dp(v);
		f[u][0]+=max(f[v][0],f[v][1]);
		f[u][1]+=f[v][0];
	}
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	for(int i=1;i<n;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		v[x]=1;
		G[y].push_back(x);
	}
	int rt;
	for(int i=1;i<=n;i++) if(!v[i]) { rt=i; break; }
	dp(rt);
	printf("%d\n",max(f[rt][0],f[rt][1]));
	return 0;
}