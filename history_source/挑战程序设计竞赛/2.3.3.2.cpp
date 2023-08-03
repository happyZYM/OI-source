#include<cstdio>
int n,m,M;
int a[1001],dp[1001][1001];
void solve()
{
	int i,j;
	for(i=0;i<=n;i++) dp[i][0]=1;
	for(i=0;i<n;i++)
		for(j=1;j<=m;j++)
			if(j-1-a[i]>=0)
				dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]+M)%M;
			else
				dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%M;
	printf("%d\n",dp[n][m]);
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	scanf("%d",&M);
}
int main()
{
	init();
	solve();
	return 0;
}
