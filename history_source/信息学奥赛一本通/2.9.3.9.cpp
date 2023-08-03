#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[50005],dp[3][50005];
void solve()
{
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	dp[1][1]=a[1];
	dp[2][1]=dp[2][0]=-500000005;
	int max1=a[1],res;
	for(int i=2;i<=n;i++)
	{
		dp[1][i]=max(a[i],dp[1][i-1]+a[i]);
		dp[2][i]=max(max1+a[i],dp[2][i-1]+a[i]);
		max1=max(max1,dp[1][i]);
	}
//	for(int i=1;i<=n;i++) printf("%11d%11d\n",dp[1][i],dp[2][i]); 
	res=dp[2][1];
	for(int i=2;i<=n;i++) res=max(res,dp[2][i]);
	printf("%d\n",res);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) solve();
	return 0;
}
/*
1
10
1 -1 2 2 3 -3 4 -4 5 -5

1
10
-4 -5 -6 -7 -8 -9 -10 -1 -2 -3
*/
