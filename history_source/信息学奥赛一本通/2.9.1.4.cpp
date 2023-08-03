#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
	int t;
	scanf("%d",&t);
	int ans[t];
	int y,x;
	int nums[110][110],dp[110][110];
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&y,&x);
		for(int ii=0;ii<y;ii++)
			for(int jj=0;jj<x;jj++)
				scanf("%d",&nums[jj][ii]);
		dp[0][0]=nums[0][0];
		for(int ii=1;ii<x;ii++) dp[ii][0]=dp[ii-1][0]+nums[ii][0];
		for(int ii=1;ii<y;ii++) dp[0][ii]=dp[0][ii-1]+nums[0][ii];
		for(int ii=1;ii<y;ii++)
			for(int jj=1;jj<x;jj++)
				dp[jj][ii]=nums[jj][ii]+max(dp[jj-1][ii],dp[jj][ii-1]);
		ans[i]=dp[x-1][y-1];
	}
	for(int i=0;i<t;i++) printf("%d\n",ans[i]);
	return 0;
}
