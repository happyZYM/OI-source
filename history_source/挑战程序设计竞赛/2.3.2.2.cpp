#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100,MAXV=100;
int n,W;
int w[MAXN+1],v[MAXN+1];
int dp[MAXN+1][MAXN*MAXV+1];
inline int max(int a,int b){return a>b?a:b;}
void solve()
{
	fill(dp[0],dp[0]+MAXN*MAXV+1,1<<30);
	dp[0][0]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=MAXN*MAXV;j++)
		if(j<v[i]) dp[i+1][j]=dp[i][j];
		else dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+w[i]);
	int res=0;
	for(int i=0;i<=MAXN*MAXV;i++) if(dp[n][i]<=W) res=i;
	printf("%d\n",res);
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
