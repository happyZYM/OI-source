#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a,b,cnta[20],cntb[20],pow10[20],f[20];
inline void solve(LL R,LL *cnt)
{
	for(int i=0;i<=9;i++) cnt[i]=0;
	int num[20]={0},len=0;
	while(R) { num[++len]=R%10; R/=10; }
	for(int i=len;i>=1;i--)
	{
		for(int j=0;j<10;j++) cnt[j]+=f[i-1]*num[i];
		for(int j=0;j<num[i];j++) cnt[j]+=pow10[i-1];
		LL lst=0;
		for(int j=i-1;j>=1;j--) lst=lst*10+num[j];
		cnt[num[i]]+=lst+1;
		cnt[0]-=pow10[i-1];
	}
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	pow10[0]=1;
	for(int i=1;i<=15;i++)
	{
		f[i]=f[i-1]*10+pow10[i-1];
		pow10[i]=pow10[i-1]*10;
	}
	while(scanf("%lld %lld",&a,&b)==2&&!(a==0&&b==0))
	{
		if(a>b) swap(a,b);
		solve(b,cntb); solve(a-1,cnta);
		for(int i=0;i<=8;i++) printf("%lld ",cntb[i]-cnta[i]); printf("%lld\n",cntb[9]-cnta[9]);
	}
	return 0;
}