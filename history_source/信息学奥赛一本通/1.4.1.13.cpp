#include<cstdio>
using namespace std;
int main()
{
	long long a,b,c;
	a=b=c=1;
	int n;
	scanf("%d",&n);
	for(int i=3;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	printf("%ld\n",c);
	return 0;
}
