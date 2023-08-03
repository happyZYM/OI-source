#include<cstdio>
using namespace std;
double fmod(double a,double b)
{
	long long x=a/b;
	return a-b*x;
}
int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	printf("%lf\n",fmod(a,b));
	return 0;
}

