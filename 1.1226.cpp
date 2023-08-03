#include<cstdio>
typedef long long LL;
LL ksm(LL a,LL b,LL p)
{
	LL res=1;
	for(;b>0;b>>=1)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
	}
	return res%p;
}
LL b,p,k;
int main()
{
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld",b,p,k,ksm(b,p,k));
	return 0;
}
