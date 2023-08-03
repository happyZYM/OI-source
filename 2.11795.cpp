#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=16;
int T,n;
int wep[1<<maxn];
long long dp[1<<maxn];
char s[maxn+5];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d",&n);
		scanf("%s",s);
		memset(wep,0,sizeof(wep));
		memset(dp,0,sizeof(dp));
		for(int i=strlen(s)-1;i>=0;i--)
			wep[0]|=(int)(s[i]-'0')<<i;
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			wep[1<<i]=wep[0];
			for(int j=strlen(s)-1;j>=0;j--)
				wep[1<<i]|=(int)(s[j]-'0')<<j;
		}
		for(int s=0;s<(1<<n);s++)
		{
			wep[s]|=wep[0];
			for(int i=0;i<n;i++)
				if(s&(1<<i)) wep[s]|=wep[1<<i];
		}
		dp[0]=1;
		for(int s=0;s<(1<<n);s++)
		{
			if(dp[s]==0) continue;
			for(int i=0;i<n;i++)
				if((wep[s]&(1<<i))&&!(s&(1<<i)))
					dp[s|(1<<i)]+=dp[s];
		}
		printf("Case %d: %lld\n",kase,dp[(1<<n)-1]);
	}
	return 0;
}
/*
0 1 2
0 2 1
1 0 2
*/
