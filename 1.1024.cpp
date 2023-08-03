#include<cstdio>
#include<cmath>
int main()
{
     double a,b,c,d;
     double as,bs,t,si;
     double x1,x2,x3;
     scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
     as=b*b-3*a*c;
     bs=b*c-9*a*d;
     t=(2*as*b-3*a*bs)/(2*sqrt(as*as*as));
     si=acos(t);
     x1=(-b-2*sqrt(as)*cos(si/3))/(3*a);
     x2=(-b+sqrt(as)*(cos(si/3)+sqrt(3)*sin(si/3)))/(3*a);
     x3=(-b+sqrt(as)*(cos(si/3)-sqrt(3)*sin(si/3)))/(3*a);
     printf("%.2lf %.2lf %.2lf\n",x1,x3,x2);
     return 0;
}
