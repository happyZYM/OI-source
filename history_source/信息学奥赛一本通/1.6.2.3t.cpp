#include<cstdio>
using namespace std;
int fan(int n)
{
	int ans=0;
	do
	{
		ans=ans*10+n%10;
		n/=10;
	}
	while(n);
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",fan(n));
	return 0;
}

