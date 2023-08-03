//http://contest-hunter.org:83/contest/0x00%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E4%BE%8B%E9%A2%98/0101%20a%5Eb
#include<cstdio>
typedef long long LL;
inline LL ksm(LL a,LL b,LL p)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%p) b&1?res=res*a%p:0;
	return res;
}
int main()
{
	LL a,b,p; scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld\n",ksm(a,b,p)%p);
	return 0;
}
