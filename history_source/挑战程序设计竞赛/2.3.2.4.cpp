#include<cstdio>
#include<algorithm>
#define INF ((int)1<<31-1)
using namespace std;
int n,a[1005],dp[1005];
void solve()
{
	fill(dp,dp+n,INF);
	for(int i=1;i<n;i++)
		*lower_bound(dp,dp+n,a[i])=a[i];
	printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
}
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
}
int main()
{
	init();
	solve();
	return 0;
}
/*
5
4 2 3 1 5
*/
