#include<cstdio>
int n,w[105],v[105],W;
int dp[10005];
inline int max(int a,int b){return a>b?a:b;}
void solve()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=w[i];j<=W;j++)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	printf("%d\n",dp[W]);
}
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d",w+i,v+i);
	scanf("%d",&W);
}
int main()
{
	init();
	solve();
	return 0;
}
