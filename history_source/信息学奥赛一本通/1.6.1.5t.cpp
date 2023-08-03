#include<cstdio>
using namespace std;
int sum(int n)
{
	int sum=1;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			sum+=i+n/i;
			if(i*i==n) sum-=i;
		}
	}
	return sum;
}
int main()
{
	for(int i=1;;i++)
		if(sum(sum(i))==i&&i!=sum(i))
		{
			printf("%d %d\n",i,sum(i));
			return 0;
		}
	return 0;
}

