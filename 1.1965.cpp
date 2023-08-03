#include<cstdio>
typedef long long LL;
LL n,m,k,x;
LL ksm(LL a,int k)
{
	LL res=1;
	for(;k>0;k>>=1)
	{
		if(k&1) res=res*a%n;
		a=a*a%n;
	}
	return res;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	printf("%lld\n",(x%n+m%n*ksm(10,k))%n);
	return 0;
}
