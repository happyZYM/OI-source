#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
const int oo=0x3f3f3f3f;
int n,a[maxn],dp[maxn],pre[maxn],nxt[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	memset(dp,oo,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		*lower_bound(dp,dp+n,a[i])=a[i];
		pre[i]=lower_bound(dp,dp+n,oo)-dp;
	}
	memset(dp,oo,sizeof(dp));
	for(int i=n-1;i>=0;i--)
	{
		*lower_bound(dp,dp+n,a[i])=a[i];
		nxt[i]=lower_bound(dp,dp+n,oo)-dp;
	}
	int res=n;
	for(int i=0;i<n;i++) res=min(res,n-(pre[i]+nxt[i]-1));
	printf("%d\n",res);
	return 0;
}
