#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=205;
int n,m;
vector<int> G[maxn],E[maxn];
double a[maxn][maxn],res=0;
void solve(int mi)
{
	memset(a,0,sizeof(a));
	int md=1<<mi;
	for(int i=1;i<n;i++)
	{
		a[i][i]=G[i].size();
		for(int j=0;j<G[i].size();j++)
			if(E[i][j]&md)
			{
				a[i][n+1]=a[i][n+1]+1;
				a[i][G[i][j]]=a[i][G[i][j]]+1;
			}
			else a[i][G[i][j]]=a[i][G[i][j]]-1;
	}
	a[n][n]=1; a[n][n+1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++) if(a[j][i]!=0) { for(int k=1;k<=n+1;k++) swap(a[i][k],a[j][k]); break; }
		for(int j=n+1;j>=i;j--) a[i][j]/=a[i][i];
		for(int j=1;j<=n;j++) if(j!=i) for(int k=n+1;k>=i;k--) a[j][k]-=a[j][i]*a[i][k];
	}
	res+=md*a[1][n+1];
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		G[u].push_back(v); E[u].push_back(w);
		if(u!=v) { G[v].push_back(u); E[v].push_back(w); }
	}
	for(int i=0;i<30;i++)
		solve(i);
	printf("%.3lf\n",res);
	return 0;
}