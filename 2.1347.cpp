#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1005;
double dp[maxn][maxn],dis[maxn][maxn];
int x[maxn],y[maxn];
int n;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++) scanf("%d%d",x+i,y+i);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		for(int i=n-1;i>=2;i--)
			for(int j=1;j<i;j++)
			{
				if(i==n-1) dp[i][j]=dis[i][n]+dis[j][n];
				else dp[i][j]=min(dp[i+1][j]+dis[i][i+1],dp[i+1][i]+dis[j][i+1]);
			}
		printf("%.2lf\n",dis[1][2]+dp[2][1]);
	}
	return 0;
}
