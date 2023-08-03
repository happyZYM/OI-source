#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000005;
const int P=13141;
char s[maxn],rs[maxn];
int n,kase;
unsigned long long H[maxn],RH[maxn],pm[maxn];
int solve()
{
	n=strlen(s+1);
	memcpy(rs,s,n+1);
	reverse(rs+1,rs+1+n);
	for(int i=1;i<=n;i++) H[i]=H[i-1]*P+(s[i]-'a'+1);
	for(int i=1;i<=n;i++) RH[i]=RH[i-1]*P+(rs[i]-'a'+1);
	int res=0;
	for(int i=1,ri=n;i<=n;i++,ri--) // 长度为奇数,以s[i]为中心
	{
		int L=0,R=min(i-1,n-i),M,now=0;
		while(L<=R)
		{
			M=(L+R)>>1;
			if(H[i-1]-H[i-1-M]*pm[M]==RH[ri-1]-RH[ri-1-M]*pm[M]) L=M+1,now=M;
			else R=M-1;
		}
		res=max(res,now*2+1);
	}
	for(int i=2,ri=n-1;i<=n;i++,ri--) // 长度为偶数,以s[i-1]和s[i]为中心
	{
		int L=0,R=min(i-1,n-i+1),M,now=0;
		while(L<=R)
		{
			M=(L+R)>>1;
			if(H[i-1]-H[i-1-M]*pm[M]==RH[ri]-RH[ri-M]*pm[M]) L=M+1,now=M;
			else R=M-1;
		}
		res=max(res,now*2);
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	pm[0]=1;
	for(int i=1;i<=1000000;i++) pm[i]=pm[i-1]*P;
	while(scanf("%s",s+1),strcmp(s+1,"END")) printf("Case %d: %d\n",++kase,solve());
	return 0;
}
