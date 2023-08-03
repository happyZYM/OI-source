#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
	int n;
	scanf("%d",&n);
	int hi[n],dp[n];
	for(int i=0;i<n;i++) scanf("%d",hi+i);
	for(int i=0;i<n;i++) dp[i]=1;
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(hi[i]<=hi[j])
				dp[i]=max(dp[i],dp[j]+1);
	int ans=dp[0];
	for(int i=1;i<n;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}
