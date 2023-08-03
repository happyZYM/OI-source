#include<cstdio>
#include<cmath>
const double pi=acos(-1.0);
double area(double a,double b,double c)
{
	double p=(a+b+c)/2.0;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
double area2(double a,double B,double C)
{
	double A=pi-B-C;
	double b=a*sin(B)/sin(A);
	double c=a*sin(C)/sin(A);
	return area(a,b,c);
}
double area3(double a,double B,double C)
{
	double A=pi-B-C;
	double r=area2(a,B,C)/a*2.0;
	return r*r*A/2;
}
int kase;
double a,b,c,A,B,C,aa,bb,cc,sa,sb,sc;
double ha,hb,hc,s,t;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%lf%lf%lf",&a,&b,&c)==3&&!(a==0&&b==0&&c==0))
	{
		A=acos((b*b+c*c-a*a)/(2.0*b*c));
		B=acos((a*a+c*c-b*b)/(2.0*a*c));
		C=acos((a*a+b*b-c*c)/(2.0*a*b));
		aa=(pi-A)/2;
		bb=(pi-B)/2;
		cc=(pi-C)/2;
		sa=area2(a,bb,cc);
		sb=area2(b,aa,cc);
		sc=area2(c,aa,bb);
		s=area(a,b,c)+sa+sb+sc;
		t=area3(a,bb,cc)+area3(b,aa,cc)+area3(c,aa,bb);
		printf("Case %d: %.2lf %.2lf\n",++kase,s,t);
	}
	return 0;
}
