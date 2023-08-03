#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=55;
int n,m,a[maxn][maxn],dp[maxn][maxn][1300],res;
inline void upd(int &a,const int &b) { b>a?a=b:0; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=n-i+1;j++) scanf("%d",&a[i][j]);
	memset(dp,-127,sizeof(dp));
	dp[n+1][0][0]=0;
	for(int c=n;c>=1;c--)
		for(int r=0,s=0;r<=n-c+1;r++,s+=a[r][c])
			for(int k=r;k<=m;k++)
				for(int l=max(0,r-1);l<=n-c;l++)
				{
					upd(dp[c][r][k],dp[c+1][l][k-r]+s);
					upd(res,dp[c][r][k]);
				}
	printf("%d\n",res);
	return 0;
}
