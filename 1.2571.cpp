#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cassert>
using namespace std;
struct Point
{
	double x,y;
	Point(double a=0,double b=0):x(a),y(b) { }
};
typedef Point Vector;
inline Vector operator+(const Vector &a,const Vector &b) { return Vector(a.x+b.x,a.y+b.y); }
inline Vector operator-(const Vector &a,const Vector &b) { return Vector(a.x-b.x,a.y-b.y); }
inline Vector operator*(const Vector &a,const double &b) { return Vector(a.x*b,a.y*b); }
inline Vector operator/(const Vector &a,const double &b) { return Vector(a.x/b,a.y/b); }
inline double Length(const Vector &a) { return sqrt(a.x*a.x+a.y*a.y); }
inline Vector Format(const Vector &a)
{
	double L=Length(a);
	return L!=0?Vector(a.x/L,a.y/L):a;
}
const double eps=1e-4;
Point A,B,C,D;
double P,Q,R,ld;
inline double cal(double x,double y)
{
	Vector E=A+Format(B-A)*x,F=C+Format(D-C)*y;
	assert(ld-y>=0);
	return x/P+Length(F-E)/R+(ld-y)/Q;
}
inline double f(double x)
{
	double l=0,r=Length(D-C),m1,m2,v1,v2,res;
	res=cal(x,0);
	while(r-l>eps)
	{
		m1=(r-l)/3+l; m2=(r-l)/3*2+l;
		v1=cal(x,m1); v2=cal(x,m2);
		if(v1>v2) l=m1,res=v2;
		else r=m2,res=v1;
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y,&D.x,&D.y);
	scanf("%lf%lf%lf",&P,&Q,&R);
	double l=0,r=Length(B-A),m1,m2,v1,v2,res;
	ld=Length(D-C);
	res=f(0);
	while(r-l>eps)
	{
		m1=(r-l)/3+l; m2=(r-l)/3*2+l;
		v1=f(m1); v2=f(m2);
		if(v1>v2) l=m1,res=v2;
		else r=m2,res=v1;
	}
	printf("%.2lf\n",res);
	return 0;
}
