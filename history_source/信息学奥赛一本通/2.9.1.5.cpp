#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
	int n;
	scanf("%d",&n);
	int num[n],dp[n];
	for(int i=0;i<n;i++) scanf("%d",num+i);
	for(int i=0;i<n;i++) dp[i]=num[i];
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(num[i]>num[j])
				dp[i]=max(dp[i],num[i]+dp[j]);
	int ans=dp[0];
	for(int i=1;i<n;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}
