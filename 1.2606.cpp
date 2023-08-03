#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e6+7;
int n; LL p;
LL fac[maxn],fac_inv[maxn],inv[maxn];
LL f[maxn];
bool is_le[maxn]; int lsize[maxn];
inline LL C(int n,int m) { return (fac[n]*fac_inv[m]%p)*fac_inv[n-m]%p; }
LL lucas(int n,int m)
{
	if(m>n) return 0;
	if(m<p&&n<p) return C(n,m);
	else return lucas(n/p,m/p)*C(n%p,m%p)%p;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%lld",&n,&p);
	fac[0]=1;		for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%p;
	inv[1]=1;		for(int i=2;i<=n;i++) inv[i]=(p-p/i)*inv[p%i]%p;
	fac_inv[0]=1;	for(int i=1;i<=n;i++) fac_inv[i]=fac_inv[i-1]*inv[i]%p;
	is_le[2]=true;	for(int i=3;i<=n;i++) is_le[i]=is_le[i>>1];
					for(int i=2;i<=n;i++) lsize[i]=lsize[i-1]+is_le[i];
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++)
	{
		LL x=lsize[i];
		f[i]=(lucas(i-1,x)*f[x]%p)*f[i-x-1]%p;
	}
	printf("%lld\n",f[n]);
	return 0;
}
