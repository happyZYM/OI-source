#include<cstdio>
using namespace std;
unsigned long long gcd(unsigned long long m,unsigned long long n) 
{
	int x=1;
	unsigned long long t;
    begin:if(m==n) return x*m;
    if(m<n) 
    {
    	t=m,m=n,n=t;
    	goto begin;
	}
    if(m&1)
    {
    	if(n&1) 
    	{
    		t=n;
    		n=m-n;
    		m=t;
    		goto begin;
		}
		n=n>>1;
		goto begin;
	}
    if(n&1)
    {
    	m=m>>1;
    	goto begin;
	}
	x=x*2;
	m=m>>1;
	n=n>>1;
	goto begin;
}
int main()
{
	unsigned long long n,m;
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",gcd(n,m));
	return 0;
}
