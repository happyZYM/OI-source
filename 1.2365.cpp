#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5005;
int n,s;
int St[maxn],Sc[maxn],dp[maxn],q[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	{
		int t,c; scanf("%d%d",&t,&c);
		St[i]=St[i-1]+t;
		Sc[i]=Sc[i-1]+c;
	}
	memset(dp,0x3f,sizeof(dp)); dp[0]=0;
	int l=1,r=1;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&(dp[q[l+1]]-dp[q[l]])<=(s+St[i])*(Sc[q[l+1]]-Sc[q[l]])) l++;
		dp[i]=dp[q[l]]-(s+St[i])*Sc[q[l]]+St[i]*Sc[i]+s*Sc[n];
		while(l<r&&(dp[q[r]]-dp[q[r-1]])*(Sc[i]-Sc[q[r]])>=(dp[i]-dp[q[r]])*(Sc[q[r]]-Sc[q[r-1]])) r--;
		q[++r]=i;
	}
	printf("%d\n",dp[n]);
	return 0;
}
