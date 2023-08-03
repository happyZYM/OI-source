#include<cstdio>
const int MAXN=105;
int n,W;
int w[MAXN],v[MAXN];
int dp[MAXN];
inline int max(int a,int b){return a>b?a:b;}
void solve()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=W;j>=w[i];j--)
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
