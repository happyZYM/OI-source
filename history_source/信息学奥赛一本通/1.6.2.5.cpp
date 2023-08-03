#include<cstdio>
using namespace std;
double f(double x,int n)
{
	if(n==1) return x/(1+x);
	return x/(n+f(x,n-1));
}
int main()
{
	double x;
	int n;
	scanf("%lf%d",&x,&n);
	printf("%g\n",f(x,n));
	return 0;
}

