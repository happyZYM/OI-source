#include<cstdio>
using namespace std;
int main()
{
	double a,b,c,d,x;
	scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&x);
	double ans=a*x*x*x+b*x*x+c*x+d;
	printf("%.7lf\n",ans);
	return 0;
}
