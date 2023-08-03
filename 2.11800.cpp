#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
using std::vector;
using std::swap;

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
using namespace std;
const char* rslts[]={"Square","Rectangle","Rhombus","Parallelogram","Trapezium","Ordinary Quadrilateral"};
int T,res;
Point p[4];
inline bool PingXing
(const Point &A1,const Point &B1,const Point &A2,const Point &B2)
{ return dcmp(Cross(B1-A1,B2-A2))==0; }
bool is_Square()
{
	sort(p,p+4);
	do
	{
		for(int i=0;i<4;i++)
		{
			Vector v1=p[(i+1)%4]-p[i],v2=p[(i+2)%4]-p[(i+1)%4];
			v1=Vector(-v1.y,v1.x);
			if(!(v1==v2)) goto next;
		}
		return true;
next:
		continue;
	}
	while(next_permutation(p,p+4));
	return false;
}
bool is_JuXin()
{
	sort(p,p+4);
	do
	{
		for(int i=0;i<4;i++)
		{
			Vector v1=p[(i+1)%4]-p[i],v2=p[(i+2)%4]-p[(i+1)%4];
			if(!(Normal(v1)==Format(v2))) goto next;
		}
		return true;
next:
		continue;
	}
	while(next_permutation(p,p+4));
	return false;
}
bool is_LinXin()
{
	sort(p,p+4);
	do
	{
		for(int i=0;i<4;i++)
		{
			Vector v1=p[(i+1)%4]-p[i],v2=p[(i+2)%4]-p[(i+1)%4];
			if(!(PingXing(p[i],p[(i+1)%4],p[(i+2)%4],p[(i+3)%4])
				&&Length(v1)==Length(v2))) goto next;
		}
		return true;
next:
		continue;
	}
	while(next_permutation(p,p+4));
	return false;
}
bool is_PingXingSiBianXin()
{
	sort(p,p+4);
	do
	{
		for(int i=0;i<4;i++)
		{
			Vector v1=p[(i+1)%4]-p[i],v2=p[(i+2)%4]-p[(i+1)%4];
			if(!(PingXing(p[i],p[(i+1)%4],p[(i+2)%4],p[(i+3)%4]))) goto next;
		}
		return true;
next:
		continue;
	}
	while(next_permutation(p,p+4));
	return false;
}
bool is_TiXin()
{
	sort(p,p+4);
	do
	{
		for(int i=0;i<4;i++)
		{
			Vector v1=p[(i+1)%4]-p[i],v2=p[(i+2)%4]-p[(i+1)%4];
			if(PingXing(p[i],p[(i+1)%4],p[(i+2)%4],p[(i+3)%4])) return true;
		}
	}
	while(next_permutation(p,p+4));
	return false;
}
int solve()
{
	if(is_Square()) return 0;
	else if(is_JuXin()) return 1;
	else if(is_LinXin()) return 2;
	else if(is_PingXingSiBianXin()) return 3;
	else if(is_TiXin()) return 4;
	return 5;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		for(int i=0;i<4;i++) p[i]=read_point();
		printf("Case %d: %s\n",kase,rslts[solve()]);
	}
	return 0;
}
