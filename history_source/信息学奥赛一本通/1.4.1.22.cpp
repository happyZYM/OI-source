#include<cstdio>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int li;
	if(a>b) li=a,a=b,b=li;
	if(b>c) li=b,b=c,c=li;
	if(a>b) li=a,a=b,b=li;
	li=a;
	a=b-a;
	b=c-b;
	for(int i=2;i<=li;i++)
	{
		if(a%i==0&&b%i==0)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}

