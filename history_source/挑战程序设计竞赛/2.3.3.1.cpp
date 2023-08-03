#include<cstdio>
int n,m,M;
int dp[1005][1005];
void solve()
{
	int i,j;
	dp[0][0]=1;
	for(i=1;i<=m;i++)
		for(j=0;j<=n;j++)
		if(j-i>=0)
			dp[i][j]=(dp[i-1][j]+dp[i][j-i])%M;
		else
			dp[i][j]=dp[i-1][j];
	printf("%d\n",dp[m][n]);
	for(i=0;i<=m;i++)
		for(j=0;j<=n;j++)
			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
}
void init()
{
	scanf("%d%d%d",&n,&m,&M);
}
int main()
{
	init();
	solve();
	return 0;
}
