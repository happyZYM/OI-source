#include<cstdio>
typedef long long LL;
LL L; int kase;
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a; }
inline LL mmul(LL a, LL b, LL m)
{
	LL d=((long double)a/m*b+0.5);
	LL r=a*b-d*m;
	return r<0?r+m:r;
}
inline LL ksm(LL a,LL b,LL p)
{
	LL res=1;
	for(;b;b>>=1,a=mmul(a,a,p)) b&1?res=mmul(res,a,p):0;
	return res;
}
inline LL phi(LL x)
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
LL solve()
{
	LL d=gcd(8,L);
	LL v=phi(9*L/d),i;
	for(i=1;i*i<=v;i++) if(v%i==0&&ksm(10,i,9*L/d)==1) return i;
	i--;
	for(;i>=1;i--) if(v%i==0&&ksm(10,v/i,9*L/d)==1) return v/i;
	return 0;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%lld",&L)==1&&L) printf("Case %d: %lld\n",++kase,solve());
	return 0;
}
