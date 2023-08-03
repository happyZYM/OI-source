#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
int main()
{
	int n;
	scanf("%d",&n);
	int prise[n][n],dp[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&prise[j][i]);
	dp[0][0]=prise[0][0];
	for(int i=1;i<n;i++) dp[i][0]=dp[i-1][0]+prise[i][0];
	for(int i=1;i<n;i++) dp[0][i]=dp[0][i-1]+prise[0][i];
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			dp[j][i]=min(dp[j-1][i],dp[j][i-1])+prise[j][i];
	printf("%d\n",dp[n-1][n-1]);
	return 0;
}
