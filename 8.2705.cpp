#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=65536;
int p[maxn],v[maxn],ph[maxn],cnt;
LL n,res;
inline int phi(LL x)
{
	LL res=x;
	for(LL i=2;i*i<=x;i++) if(x%i==0)
	{
		res=res/i*(i-1);
		while(x%i==0) x/=i;
	}
	if(x>1) res=res/x*(x-1);
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld",&n);
	res=0;
	for(LL i=1;i*i<=n;i++) if(n%i==0)
	{
		res+=i*phi(n/i);
		if(i*i<n) res+=n/i*phi(i);
	}
	printf("%lld\n",res);
	return 0;
}
