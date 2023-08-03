#include<cstdio>
#include<cmath>
using namespace std;
double f(double x,int n)
{
	if(n==1) return sqrt(1+x);
	return sqrt(n+f(n-1,x));
}
int main()
{
	printf("%g\n%g\n",f(4.2,10),f(2.5,15));
	return 0;
}

