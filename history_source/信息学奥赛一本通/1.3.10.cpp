#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double x1,x2,a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	x1=(-b+sqrt(b*b-4*a*c))/(2*a);
	x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	printf("%.5lf\n%.5lf\n",x1,x2);
	return 0;
}

