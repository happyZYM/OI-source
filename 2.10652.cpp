#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
using std::sort;

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

const double ops=1e-10;
inline int dcmp(double x)
{ return (x>0?x:-x)<ops?0:(x>0?1:-1); }

const double Pi=atan(1)*4;
inline double D_to_R(double D)
{ return Pi/180*D; }

inline double Cross(const Vector &A,const Vector &B)
{ return A.x*B.y-A.y*B.x; }

inline Vector Rotate(const Vector &A,double rad)
{
	double csr=cos(rad),sir=sin(rad);
	return Vector(A.x*csr-A.y*sir,A.x*sir+A.y*csr);
}

inline double PolygonArea(Point* p,int n)
{
	double area=0;
	for(int i=1;i<n-1;i++)
		area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
}
int ConvexHull(Point *p,int n,Point *ch)
{
	sort(p,p+n);
	int m=0;
	for(int i=0;i<n;i++)
	{
		while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--)
	{
		while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	}
	if(n>1) m--;
	return m;
}
using namespace std;
int T;
Point P[2500],ch[2500];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		int n,pc=0;
		double area1=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			double x,y,w,h,j,ang;
			scanf("%lf%lf%lf%lf%lf",&x,&y,&w,&h,&j);
			Point o(x,y);
			ang=-D_to_R(j);
			P[pc++]=o+Rotate(Vector(-w/2,-h/2),ang);
			P[pc++]=o+Rotate(Vector(-w/2,h/2),ang);
			P[pc++]=o+Rotate(Vector(w/2,-h/2),ang);
			P[pc++]=o+Rotate(Vector(w/2,h/2),ang);
			area1+=w*h;
		}
		int m=ConvexHull(P,pc,ch);
		double area2=PolygonArea(ch,m);
		printf("%.1lf %%\n",area1*100/area2);
	}
	return 0;
}
