#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	do
	{
		printf("%d ",n%10);
		n/=10;
	}
	while(n);
	printf("\n");
	return 0;
}

