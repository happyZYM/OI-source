#include<cstdio>
#include<algorithm>
#include<cassert>
using namespace std;
typedef long long LL;
LL n,m,l,mod;
inline LL mmul(LL a,LL b,LL m=mod)
{
	LL d=((long double)a/m*b+1e-8);
	LL r=a*b-d*m;
	return r<0?r+m:r;
}
LL phi(LL x)
{
	LL res=1;
	for(LL i=2;i*i<=x;i++)
		if(x%i==0)
		{
			res=res*(i-1);
			while(x%i==0) res=res*i,x/=i;
		}
	if(x>1) res=res*(x-1);
	return res;
}
LL ksm(LL a,LL n)
{
	LL res=1;
	for(;n;n>>=1,a=mmul(a,a)) n&1?res=mmul(res,a):0;
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld%lld",&n,&m,&l);
	mod=n+1;
	LL res=mmul(l,ksm(ksm(2,phi(mod)-1),m));
	printf("%lld\n",res?res:mod);
	return 0;
}
