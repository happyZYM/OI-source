#include<cstdio>
int one=0,zero=0;
bool isa(int n)
{
	one=zero=0;
	do
	{
		if(n&1) one++;
		else zero++;
		n>>=1;
	}
	while(n);
	return one>zero;
}
int main()
{
	int a=0,b=0;
	for(int i=1;i<=1000;i++)
	{
		if(isa(i)) a++;
		else b++;
	}
	printf("%d %d\n",a,b);
	return 0;
}
