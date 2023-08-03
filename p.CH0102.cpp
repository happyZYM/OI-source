//http://contest-hunter.org:83/contest/0x00%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E4%BE%8B%E9%A2%98/0102%2064%E4%BD%8D%E6%95%B4%E6%95%B0%E4%B9%98%E6%B3%95
#include<cstdio>
typedef long long LL;
LL mmul(LL a,LL b,LL p)
{
	LL d=(long double)b/p*a+1e-8;
	LL r=a*b-d*p;
	return r<0?r+p:r;
}
int main()
{
	LL a,b,p; scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld\n",mmul(a,b,p));
	return 0;
}
