#include<cstdio>
#include<algorithm>
using namespace std;
int p,q,a[105];
int dp[105][105];
void init()
{
	scanf("%d%d",&p,&q);
	for(int i=1;i<=q;i++) scanf("%d",a+i);
}
void solve()
{
	a[0]=0;
	a[q+1]=p+1;
	for(int i=0;i<=q;i++) dp[i][i+1]=0;
	for(int w=2;w<=q+1;w++)
	{
		for(int i=0;i+w<=q+1;i++)
		{
			int j=i+w,t=1<<30;for(int k=i+1;k<j;k++)
				t=min(t,dp[i][k]+dp[k][j]);
			dp[i][j]=t+a[j]-a[i]-2;
		}
	}
	printf("%d\n",dp[0][q+1]);
}
int main()
{
	init();
	solve();
	return 0;
}
