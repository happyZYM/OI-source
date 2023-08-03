#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,m[105],p[105],dp[105];
void solve()
{
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",m+i);
	for(int i=0;i<n;i++) scanf("%d",p+i);
	int res=0;
	for(int i=0;i<n;i++)
	{
		dp[i]=p[i];
		for(int j=0;j<i&&m[i]-m[j]>k;j++)
			dp[i]=max(dp[i],dp[j]+p[i]);
		res=max(res,dp[i]);
	}
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
2

3 11
1 2 15
10 2 30

3 16
1 2 15
10 2 30
*/
