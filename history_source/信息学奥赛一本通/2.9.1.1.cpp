#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
	int len;
	scanf("%d",&len);
	int num[len];
	for(int i=0;i<len;i++) scanf("%d",num+i);
	int dp[len];
	for(int i=0;i<len;i++) dp[i]=1;
	for(int i=1;i<len;i++) 
		for(int j=0;j<i;j++)
			if(num[i]>num[j])
				dp[i]=max(dp[i],dp[j]+1);
	int ans=dp[0];
	for(int i=1;i<len;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0; 
}
