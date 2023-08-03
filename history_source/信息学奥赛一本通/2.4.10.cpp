#include<cstdio>
long long t;
long long gcd(long long a,long long b)
{
	if(a==b) return a;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	if(a&1)
	{
		if(b&1) return gcd(b,a-b);
		else return gcd(a,b>>1);
	}
	else
	{
		if(b&1) return gcd(a>>1,b);
		return 2*gcd(a>>1,b>>1);
	}
}
int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld\n",gcd(a,b));
	return 0;
}

