#include<cstdio>
#include<cstring>
const int maxn=55;
int n,m,a[maxn][maxn],dp[2*maxn][maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	memset(dp,-1,sizeof(dp));
	dp[2][1][1]=0;
	for(int k=3;k<=n+m-1;k++)
		for(int x1=1;x1<m;x1++)
			for(int x2=x1+1;x2<=m;x2++)
			{
				int s=dp[k][x1][x2];
				if(dp[k-1][x1][x2]>s) s=dp[k-1][x1][x2];
				if(dp[k-1][x1][x2-1]>s) s=dp[k-1][x1][x2-1];
				if(dp[k-1][x1-1][x2]>s) s=dp[k-1][x1-1][x2];
				if(dp[k-1][x1-1][x2-1]>s) s=dp[k-1][x1-1][x2-1];
				if(s==-1) continue;
				dp[k][x1][x2]=s+a[k-x1][x1]+a[k-x2][x2];
			}
	printf("%d\n",dp[m+n-1][m-1][m]);
	return 0;
}
