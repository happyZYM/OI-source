#include<cstdio>
#include<cmath> 
using namespace std;
int main()
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	if(!(a+b>c&&a+c>b&&b+c>a)) printf("no\n");
	else
	{
		double p=(a+b+c)/2.0;
		double ans=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("%lf\n",ans);
	}
	return 0;
}

