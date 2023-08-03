#include<cstdio>
int dp[1001]={1},minus[]={0,10,20,50,100},i,j,k,n;
int main()
{
	scanf("%d",&n);
	if(n%10>0||n==0)
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=4;i++)
		for(j=n;j>=minus[i];j--)
			for(k=1;k<=j/minus[i];k++)
				dp[j]+=dp[j-k*minus[i]];
	printf("%d\n",dp[n]);
	return 0;
}
