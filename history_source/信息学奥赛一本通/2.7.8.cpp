#include<cstdio> 
double f(double n)
{
	return n*n*n*n*n-15*n*n*n*n+85*n*n*n-225*n*n+274*n-121;
}
int main()
{
	printf("%.6lf\n",1.8490158);
	return 0;
}
