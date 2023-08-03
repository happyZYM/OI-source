//https://www.acwing.com/problem/content/322/
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=205;
int n,a[maxn],dp[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	int len=n;
	n=2*n-1;
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int l=i,r=i+len-1;
			for(int j=l;j<r;j++)
				dp[l][r]=max(dp[l][r],dp[l][j]+dp[j+1][r]+a[l]*a[j+1]*a[r+1]);
		}
	int res=0;
	for(int i=1;i+len-1<=n;i++) res=max(res,dp[i][i+len-1]);
	printf("%d\n",res);
	return 0;
}