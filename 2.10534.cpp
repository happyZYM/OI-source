#include<cstdio>
#include<algorithm>
using namespace std;
const int oo=1e9;
const int maxn=10005;
int n;
int a[maxn],dp[maxn],f1[maxn],f2[maxn];
void DP(int *f)
{
	fill(dp,dp+maxn,oo);
	for(int i=0;i<n;i++)
	{
		int k=lower_bound(dp+1,dp+n+1,a[i])-dp;
		dp[k]=a[i];
		f[i]=k;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		DP(f1);
		reverse(a,a+n);
		DP(f2);
		int res=0;
		for(int i=0;i<n;i++)
			res=max(res,min(f1[i],f2[n-i-1])*2-1);
		printf("%d\n",res);
	}
	return 0;
}
