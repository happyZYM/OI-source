#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int w[n+1],p[n+1];
	for(int i=1;i<=n;i++)
		scanf("%d%d",w+i,p+i);
	int dp[n+1][m+1]={0};
	for(int i=1;i<=n;i++)
		for(int j=m;j>0;j--)
			if(w[i]<=j) dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
			else dp[i][j]=dp[i-1][j];
	printf("%d\n",dp[n][m]);
	return 0;
}
