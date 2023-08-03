#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
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

const double Pi=acos(-1);
const double eps=5e-13;
inline int dcmp(double x)
{ return (x>0?x:-x)<eps?0:(x>0?1:-1); }

inline bool operator==(const Point &a,const Point &b)
{ return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0; }

inline double Dot(const Vector &A,const Vector &B)
{ return A.x*B.x+A.y*B.y; }

inline double Length(const Vector &A)
{ return sqrt(Dot(A,A)); }

inline double Angle(const Vector &A)
{ return atan2(A.y,A.x); }

struct Circle
{
	Point c;
	double r;
	Circle(Point c=Point(),double r=0):c(c),r(r){}
	inline Point point(double a,double delta)
	{ return Point(c.x+cos(a)*(r+delta),c.y+sin(a)*(r+delta)); }
};
inline Circle read_circle()
{
	Circle C;
	scanf("%lf%lf%lf",&C.c.x,&C.c.y,&C.r);
	return C;
}
using namespace std;
int n;
Circle c[105];
bool cansee[105],flag;
inline bool in(const Point &p,const Circle &c)
{ return dcmp(Length(c.c-p)-c.r)<=0; }
vector<double> ang;
void intersectangle(int i,int j)
{
    double d=Length(c[i].c-c[j].c);
    if (dcmp(d-fabs(c[i].r-c[j].r))<=0
	||dcmp(d-c[i].r-c[j].r)>=0) return;
    double x=Angle(c[j].c-c[i].c),
	y=acos((c[i].r*c[i].r+d*d-c[j].r*c[j].r)/2/c[i].r/d);
    ang.push_back(x+y);
    ang.push_back(x-y);
}
void mark(const Point &p)
{
	for(int i=n-1;i>=0;i--)
		if(in(p,c[i]))
		{
			cansee[i]=true;
			return;
		}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++) c[i]=read_circle();
		memset(cansee,0,sizeof(cansee));
		for(int i=0;i<n;i++)
		{
			ang.clear();
			for(int j=0;j<n;j++)
				if(i!=j)
					intersectangle(i,j);
			if(ang.empty())
			{
				mark(c[i].point(0,eps));
				mark(c[i].point(0,-eps));
				continue;
			}
			sort(ang.begin(),ang.end());
			for(int j=0;j<ang.size();j++)
			{
				double x=(ang[j]+ang[(j+1)%n])/2;
				mark(c[i].point(x,eps));
				mark(c[i].point(x,-eps));
			}
		}
		int res=0;
		for(int i=0;i<n;i++) res+=cansee[i];
		printf("%d\n",res);
	}
	return 0;
}
