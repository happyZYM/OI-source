#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=2520;
const int maxmem=mod*105*10;
int L,S,T,M;
int stones[105],dp[maxmem];
bool flag[maxmem];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d%d",&L,&S,&T,&M);
	for(int i=1;i<=M;i++) scanf("%d",&stones[i]);
	sort(stones+1,stones+1+M); 
	stones[M+1]=L;
	for(int i=1;i<=M+1;i++) stones[i]=stones[i-1]+(stones[i]-stones[i-1])%mod;
	for(int i=1;i<=M;i++) flag[stones[i]]=true;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	L=stones[M+1];
	for(int i=1;i<=L+T;i++)
		for(int j=S;j<=T;j++)
			if(i-j>=0)
				dp[i]=min(dp[i],dp[i-j]+flag[i]);
	int res=dp[L];
	for(int i=L;i<=L+T;i++) res=min(res,dp[i]);
	printf("%d\n",res);
	return 0;
}
