#include<cstdio>
inline int min(int a,int b){return a<b?a:b;}
int a[501],dp[501][501],b[501][501],oo=99999999;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",a+i);
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<=j;k++)
				b[i][j]+=min(a[k]-a[i],a[j]-a[k]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			dp[1][i]+=a[i]-a[j];
	for(int i=2;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=oo;
			for(int k=1;k<=j;k++)
			dp[i][j]=min(dp[i-1][k]+b[k][j],dp[i][j]);
		}
	int ans=oo;
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=i;j<=n;j++)
			x+=a[j]-a[i];
		ans=min(ans,dp[m][i]+x);
	}
	printf("%d\n",ans);
	return 0;
}
