#include<cstdio>
#include<cstring> 
#include<algorithm>
using namespace std;
int n,m,dp[110][110];
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				dp[i][j]=i;
		for(int i=1;i<=n;i++)
			for(int j=2;j<=m;j++)
				for(int k=2;k<=i;k++)
					dp[i][j]=min(dp[i][j],max(dp[k-1][j-1],dp[i-k][j])+1);
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
