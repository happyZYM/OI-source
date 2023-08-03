#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
	int t,n;
	scanf("%d",&t);
	int ans[t],a,dp1,dp2,dp3,dp4;
	int money;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		a=0;
		dp1=dp2=dp3=dp4=0;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&money);
			dp4=max(dp1,dp2)+money;
			dp1=dp2;
			dp2=dp3;
			dp3=dp4;
			if(dp4>a) a=dp4; 
		}
		ans[i]=a;
	}
	for(int i=0;i<t;i++) printf("%d\n",ans[i]);
	return 0;
}
