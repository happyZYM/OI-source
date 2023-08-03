#include<cstdio>
using namespace std;
bool isw(int n)
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
	return sum==n;
}
int main()
{
	for(int i=2;i<=100;i++)
		if(isw(i)) printf("%d\n",i);
	return 0;
}

