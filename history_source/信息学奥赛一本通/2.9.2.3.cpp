#include<cstdio>
int n,m,k,ans,cost,hurt,**dp;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	dp=new int*[n+1];
	for(int i=0;i<=n;i++) dp[i]=new int[m+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++) dp[i][j]=0;
	for(int i=1;i<=k;i++)
	{
		cost=0,hurt=0;
		scanf("%d%d",&cost,&hurt);
		for(int a=n;a>=cost;a--)
			for(int b=m;b>=hurt;b--)
				if(dp[a-cost][b-hurt]+1>dp[a][b]) dp[a][b]=dp[a-cost][b-hurt]+1;
	}
	for(int i=0;i<=m;i++)
		if(dp[n][i]==dp[n][m])
		{
			ans=m-i;
			break;
		}
	printf("%d %d\n",dp[n][m],ans);
	return 0;
}
