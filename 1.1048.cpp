#include<cstdio>
#include<algorithm>
using namespace std;
int dp[1005];
int n,T;
int w[105],v[105];
int main()
{
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++) scanf("%d%d",w+i,v+i);
	for(int i=1;i<=n;i++)
		for(int j=T;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	printf("%d\n",dp[T]);
	return 0;
}
