#include<cstdio>
using namespace std;
double f(double x)
{
	if(x>=0&&x<5) return -x+2.5;
	if(x>=5&&x<10) return 2-1.5*(x-3)*(x-3);
	if(x>=10&&x<20) return x/2.0-1.5;
}
int main()
{
	double n;
	scanf("%lf",&n);
	printf("%lf\n",f(n));
	return 0;
}

