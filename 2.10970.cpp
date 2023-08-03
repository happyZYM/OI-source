#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=305;
int n,m;
int dp[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int i=1;i<=300;i++)
		for(int j=1;j<=300;j++)
			if(i==1&&j==1) dp[i][j]=0;
			else
			{
				dp[i][j]=1<<29;
				for(int k=1;k<=i-1;k++)
					dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
				for(int k=1;k<=j-1;k++)
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
			}
	while(scanf("%d%d",&n,&m)==2) printf("%d\n",dp[n][m]);
	return 0;
}
