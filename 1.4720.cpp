#include<cstdio>
#define sqrt __builtin_sqrt//#include<cmath>
using namespace std;
typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(!b) { x=1; y=0; return a; }
	LL d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}
LL n,m,p;
inline LL pow(LL a,LL b,LL mod)
{
	LL res;
	for(res=1;b;b>>=1,a=a*a%mod) if(b&1) res=res*a%mod;
	return res;
}
inline LL inv(LL n,LL mod)
{
	LL x,y;
	exgcd(n,mod,x,y);
	return (x%mod+mod)%mod;
}
inline LL fac(LL n,LL pi,LL pk)
{
	if(!n) return 1;
	LL res=1;
	for(LL i=2;i<=pk;++i) if(i%pi) (res*=i)%=pk;
	res=pow(res,n/pk,pk);
	for(LL i=2;i<=n%pk;++i) if(i%pi) (res*=i)%=pk;
	return res*fac(n/pi,pi,pk)%pk;
}
inline LL CRT(LL b,LL mod) { return b*inv(p/mod,mod)%p*(p/mod)%p; }
inline LL C(LL n,LL m,LL pi,LL pk)
{
	LL up=fac(n,pi,pk),d1=fac(m,pi,pk),d2=fac(n-m,pi,pk);
	LL k=0;
	for(LL i=n;i;i/=pi) k+=i/pi;
	for(LL i=m;i;i/=pi) k-=i/pi;
	for(LL i=n-m;i;i/=pi) k-=i/pi;
	return up*inv(d1,pk)%pk*inv(d2,pk)%pk*pow(pi,k,pk)%pk;
}
LL exlucas(LL n,LL m)
{
	LL res=0,tmp=p,pk;
	int mx=sqrt(p)+5;
	for(int i=2;i<=mx;++i)
		if(tmp%i==0)
		{
			pk=1; while(tmp%i==0) pk*=i,tmp/=i;
			(res+=CRT(C(n,m,i,pk),pk))%=p;
		}
	if(tmp>1) (res+=CRT(C(n,m,tmp,tmp),tmp))%=p;
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld%lld",&n,&m,&p);
	printf("%lld\n",exlucas(n,m));
	return 0;
}
