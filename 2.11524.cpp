#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;

inline Vector operator+(const Vector &A,const Vector &B)
{ return Vector(A.x+B.x,A.y+B.y); }

inline Vector operator-(const Point &a,const Point &b)
{ return Vector(a.x-b.x,a.y-b.y); }

inline Vector operator*(const Vector &A,double p)
{ return Vector(A.x*p,A.y*p); }

inline Vector operator/(const Vector &A,double p)
{ return Vector(A.x/p,A.y/p); }

inline bool operator<(const Point &a,const Point &b)
{ return a.x<b.x||(a.x==b.x&&a.y<b.y); }

const double eps=1e-10;
inline int dcmp(double x)
{ return (x>0?x:-x)<=eps?0:(x>0?1:-1); }

inline bool operator==(const Point &a,const Point &b)
{ return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0; }

inline double Dot(const Vector &A,const Vector &B)
{ return A.x*B.x+A.y*B.y; }

inline double Length(const Vector &A)
{ return sqrt(Dot(A,A)); }

inline double Cross(const Vector &A,const Vector &B)
{ return A.x*B.y-A.y*B.x; }

inline Vector Normal(const Vector &A)
{
	double L=Length(A);
	return Vector(-A.y/L,A.x/L);
}
inline Vector Format(const Vector &A)
{
	double L=Length(A);
	return Vector(A.x/L,A.y/L);
}

inline double DistanceToLine
(const Point &P,const Point &A,const Point &B)
{
	Vector v1=B-A,v2=P-A;
	return fabs(Cross(v1,v2))/Length(v1);
}

struct Circle
{
	Point c;
	double r;
	Circle(Point c=Point(),double r=0):c(c),r(r){}
	inline Point point(double a)
	{ return Point(c.x+cos(a)*r,c.y+sin(a)*r); }
};

inline int GetCircleCircleIntersection
(Circle C1,Circle C2,vector<Point> &sol)
{
	if(C1.r<C2.r) swap(C1,C2);//to make sure C1 is bigger than C2
	double D=Length(C1.c-C2.c);
	if(dcmp(D)==0)
		return dcmp(C1.r-C2.r)==0?-1:0;
	if(dcmp(C1.r+C2.r-D)<0) return 0;
	if(dcmp(fabs(C1.r-C2.r)-D)>0) return 0;
	
	double d1=((C1.r*C1.r-C2.r*C2.r)/D+D)/2;
	double x=sqrt(C1.r*C1.r-d1*d1);
	Point O=C1.c+Format(C2.c-C1.c)*d1;
	Point P1=O+Normal(O-C2.c)*x,P2=O-Normal(O-C2.c)*x;
	sol.push_back(P1);
	if(P1==P2) return 1;
	sol.push_back(P2);
	return 2;
}

Circle NeiJieYuan(Point p1,Point p2,Point p3)
{
	double a=Length(p2-p3);
	double b=Length(p3-p1);
	double c=Length(p1-p2);
	Point p=(p1*a+p2*b+p3*c)/(a+b+c);
	return Circle(p,DistanceToLine(p,p1,p2));
}
int T;
double r,a1,b1,a2,b2,a3,b3;
double a,b,c;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf",&r,&a1,&b1,&a2,&b2,&a3,&b3);
		c=a1+b1;
		a=b1+b1*b2/a2;
		b=a1+a1*a3/b3;
		Point B(0,0),C(a,0),A;
		vector<Point> v;
		GetCircleCircleIntersection(Circle(B,c),Circle(C,b),v);
		A=v[0];
		Circle O=NeiJieYuan(A,B,C);
		double d=r/O.r;
		a*=d;
		b*=d;
		c*=d;
		double p=(a+b+c)/2;
		printf("%.4lf\n",sqrt(p*(p-a)*(p-b)*(p-c)));
	}
	return 0;
}
