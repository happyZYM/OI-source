#include<cstdio>
#include<cmath>
using namespace std;
struct Point
{
	double x,y;
};
double lenth(Point A,Point B)
{
	double a=abs(A.x-B.x),b=abs(A.y-B.y),c=sqrt(a*a+b*b);
	return c;
}
int main()
{
	Point A,B,C;
	scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
	double a,b,c;
	a=lenth(A,B);
	b=lenth(B,C);
	c=lenth(C,A);
	double p=(a+b+c)/2.0;
	double ans=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.2lf\n",ans);
	return 0;
}
