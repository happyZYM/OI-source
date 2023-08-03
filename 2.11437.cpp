#include<cstdio>
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;

inline Point read_point()
{
	Point A;
	scanf("%lf%lf",&A.x,&A.y);
	return A;
}

inline Vector operator+(const Vector &A,const Vector &B)
{ return Vector(A.x+B.x,A.y+B.y); }

inline Vector operator-(const Point &a,const Point &b)
{ return Vector(a.x-b.x,a.y-b.y); }

inline Vector operator*(const Vector &A,double p)
{ return Vector(A.x*p,A.y*p); }

inline Vector operator/(const Vector &A,double p)
{ return Vector(A.x/p,A.y/p); }

inline double Cross(const Vector &A,const Vector &B)
{ return A.x*B.y-A.y*B.x; }

inline double Area2(const Point &a,const Point &b,const Point &c)
{ return Cross(b-a,c-a); }

inline Point GetLineIntersection
(const Point &A1,const Point &B1,const Point &A2,const Point &B2)
{
	Vector u=A1-A2,v=B1-A1,w=B2-A2;
	double t=Cross(w,u)/Cross(v,w);
	return A1+v*t;
}
int n;
Point A,B,C,D,E,F,P,Q,R;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	while(n-->0)
	{
		A=read_point();B=read_point();C=read_point();
		D=B+(C-B)/3;
		E=C+(A-C)/3;
		F=A+(B-A)/3;
		P=GetLineIntersection(B,E,D,A);
		Q=GetLineIntersection(B,E,C,F);
		R=GetLineIntersection(D,A,C,F);
		printf("%.0lf\n",Area2(P,Q,R)/2);
	}
	return 0;
}
