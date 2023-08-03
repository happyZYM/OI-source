#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=1005;
char s[maxn];
int n,dp[maxn][maxn];
string res[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%s",s)==1)
	{
		n=strlen(s);
		for(int len=1;len<=n;len++)
			for(int L=0;L+len<=n;L++)
			{
				int R=L+len-1;
				if(L==R)
				{
					dp[L][R]=1;
					res[L][R]=s[L];
				}
				else
				{
					dp[L][R]=dp[L+1][R-1]+(s[L]==s[R]?2:0);
					dp[L][R]=max(dp[L][R],dp[L+1][R]);
					dp[L][R]=max(dp[L][R],dp[L][R-1]);
					res[L][R]="{";
					if(dp[L][R]==dp[L+1][R-1]+(s[L]==s[R]?2:0))
					{
						if(s[L]==s[R])
							res[L][R]=s[L]+res[L+1][R-1]+s[R];
						else
							res[L][R]=res[L+1][R-1];
					}
					if(dp[L][R]==dp[L+1][R])
						res[L][R]=min(res[L][R],res[L+1][R]);
					if(dp[L][R]==dp[L][R-1])
						res[L][R]=min(res[L][R],res[L][R-1]);
				}
//				printf("dp[%d][%d]=%d ",L,R,dp[L][R]);
//				printf("res[%d][%d]=%s\n",L,R,res[L][R].c_str());
			}
		printf("%s\n",res[0][n-1].c_str());
	}
	return 0;
}
/*
Sample Input
aabbaabb
computer
abzla
samhita

Sample Output
aabbaa
c
aba
aha
*/
