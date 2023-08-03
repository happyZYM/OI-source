#include<cstdio>
#include<cmath>
using namespace std;
struct Point
{
	double x,y;
};
int main()
{
	Point p1,p2;
	scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
	double a=abs(p1.x-p2.x),b=abs(p1.y-p2.y),c=sqrt(a*a+b*b);
	printf("%.3lf\n",c);
	return 0;
}

