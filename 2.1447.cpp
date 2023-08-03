#include<cstdio>
#include<cmath>
struct Point
{ double x, y; };
Point A,B,C,I;
inline double get_dis(Point p1,Point p2)
{ return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)); }
double a,b,c,s,r,IA,IB,IC,r1,r2,r3;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    while(scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y)==6)
	{
        if(A.x==0&&A.y==0&&B.x==0&&B.y==0&&C.x==0&&C.y==0) break;
        a=get_dis(B,C);
        b=get_dis(A,C);
        c=get_dis(A,B);
        s=(a+b+c)/2;
        I.x=(a*A.x+b*B.x+c*C.x)/(a+b+c);
        I.y=(a*A.y+b*B.y+c*C.y)/(a+b+c);
        r=sqrt((s-a)*(s-b)*(s-c)/s);
        IA=get_dis(A,I);
        IB=get_dis(B,I);
        IC=get_dis(C,I);
        r1=r/(2*(s-a))*(s-r+IA-IB-IC);
        r2=r/(2*(s-b))*(s-r+IB-IA-IC);
        r3=r/(2*(s-c))*(s-r+IC-IA-IB);
        printf("%.6lf %.6lf %.6lf\n",r1,r2,r3);
    }
    return 0;
}
