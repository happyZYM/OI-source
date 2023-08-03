#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1000000007;
const int maxn=1005;
const int maxm=205;
int n,m,k;
char A[maxn],B[maxm];
int dp[2][maxm][maxm][2],pos=1; 
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",A+1,B+1);
	dp[0][0][0][0]=dp[1][0][0][0]=1;
	for(int i=1;i<=n;i++,pos^=1)
		for(int j=1;j<=m;j++)
			for(int p=1;p<=k;p++)
				if(A[i]==B[j])
				{
					dp[pos][j][p][0]=(dp[pos^1][j][p][0]+dp[pos^1][j][p][1])%mod;
					dp[pos][j][p][1]=(dp[pos^1][j-1][p][1]+
									  (dp[pos^1][j-1][p-1][0]+dp[pos^1][j-1][p-1][1])%mod
									 )%mod;
				}
				else
				{
					dp[pos][j][p][0]=(dp[pos^1][j][p][0]+dp[pos^1][j][p][1])%mod;
					dp[pos][j][p][1]=0;
				}
	printf("%d\n",(dp[n&1][m][k][0]+dp[n&1][m][k][1])%mod);
	return 0;
}
