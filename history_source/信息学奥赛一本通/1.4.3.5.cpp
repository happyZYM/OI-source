#include<cstdio>
using namespace std;
int main()
{
	long long a,b=0;
	scanf("%lld",&a);
	do
	{
		b=b*10+a%10;
		a/=10;
	}
	while(a);
	printf("%lld\n",b);
	return 0;
}

