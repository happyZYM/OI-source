#include<cstdio>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	while(n>1)
	{
		if(n&1)
		{
			printf("%lld*3+1=%lld\n",n,n*3+1);
			n=n*3+1;
		}
		else 
		{
			printf("%lld/2=%lld\n",n,n/2);
			n=n/2;
		}
	}
	printf("End\n");
	return 0;
}
