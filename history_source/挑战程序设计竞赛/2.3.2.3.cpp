#include<cstdio>
#include<cstring>
int n,k,a[105],m[105];
int dp[100005];
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++) scanf("%d",m+i);
	scanf("%d",&k);
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=k;j++)
			if(dp[j]>=0) dp[j]=m[i];
			else if(j<a[i]||dp[j-a[i]]<=0) dp[j]=-1;
			else dp[j]=dp[j-a[i]]-1;
	if(dp[k]>=0) printf("Yes\n");
	else printf("No\n");
}
int main()
{
	init();
	solve();
	return 0;
}
