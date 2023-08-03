#include<cstdio>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	a=a%1000;
	int x=a;
	for(int i=1;i<b;i++)
	{
		a*=x;
		a=a%1000;
	}
	printf("%03d\n",a);
	return 0;
}

