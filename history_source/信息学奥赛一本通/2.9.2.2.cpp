#include<cstdio>
int dp[25][1005],a[25];
int n,t;
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	dp[0][0]=1;
	dp[0][a[0]]=1;
//	printf(" 0: ");
//	for(int j=0;j<=t;j++) printf("%5d",dp[0][j]);
//	printf("\n");
	for(int i=1;i<n;i++)
	{
//		printf("%2d: ",i);
		for(int j=0;j<=t;j++)
		{
			if(j<a[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
//			printf("%5d",dp[i][j]);
		}
//		printf("\n");
	}
	printf("%d\n",dp[n-1][t]);
	return 0;
}
/*
5 5
1 2 3 4 5
*/
