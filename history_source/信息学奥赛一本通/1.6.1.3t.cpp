#include<cstdio>
using namespace std;
double max(double a,double b,double c)
{
	if(a>b)
	{
		if(a>c) return a;
		return c;
	}
	else
	{
		if(b>c) return b;
		return c;
	}
}
int main()
{
	double m,a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	m=max(a,b,c)/(max(a+b,b,c)*max(a,b,b+c));
	printf("%g\n",m);
	return 0;
}
