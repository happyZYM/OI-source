#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
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

const double ops=1e-10;
inline int dcmp(double x)
{ return (x>0?x:-x)<ops?0:(x>0?1:-1); }

inline bool operator==(const Point &a,const Point &b)
{ return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0; }

inline double Dot(const Vector &A,const Vector &B)
{ return A.x*B.x+A.y*B.y; }

inline double Length(const Vector &A)
{ return sqrt(Dot(A,A)); }

inline double Angle(const Vector &A,const Vector &B)
{ return acos(Dot(A,B)/Length(A)/Length(B)); }

const double Pi=atan(1)*4;
inline double PAG(const Vector &A)
{ return atan2(A.y,A.x); }
inline double R_to_D(double rad)
{ return 180/Pi*rad; }
inline double D_to_R(double D)
{ return Pi/180*D; }

inline double Cross(const Vector &A,const Vector &B)
{ return A.x*B.y-A.y*B.x; }

inline double Area2(const Point &a,const Point &b,const Point &c)
{ return Cross(b-a,c-a); }

inline Vector Rotate(const Vector &A,double rad)
{
	double csr=cos(rad),sir=sin(rad);
	return Vector(A.x*csr-A.y*sir,A.x*sir+A.y*csr);
}

inline Vector Normal(const Vector &A)
{
	double L=Length(A);
	return Vector(-A.y/L,A.x/L);
}

inline Point GetLineIntersection
(const Point &P,const Vector &v,const Point &Q,const Vector &w)
{
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;
}

inline double DistanceToLine
(const Point &P,const Point &A,const Point &B)
{
	Vector v1=B-A,v2=P-A;
	return fabs(Cross(v1,v2))/Length(v1);
}

inline double DistanceToSegment
(const Point &P,const Point &A,const Point &B)
{
	if(A==B) return Length(P-A);
	Vector v1=B-A,v2=P-A,v3=P-B;
	if(dcmp(Dot(v1,v2))<0) return Length(v2);
	else if(dcmp(Dot(v1,v3))>0) return Length(v3);
	else return fabs(Cross(v1,v2))/Length(v1);
}

inline Point GetLineProjection
(const Point &P,const Point &A,const Point &B)
{
	Vector v=B-A;
	return A+v*(Dot(v,P-A)/Dot(v,v));
}

inline bool SegmentProperIntersection
(const Point &a1,const Point &a2,const Point &b1,const Point &b2)
{
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
		   c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}

inline bool OnSegment
(const Point &p,const Point &a1,const Point &a2)
{ return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0; }

inline double PolygonArea(Point* p,int n)
{
	double area=0;
	for(int i=1;i<n-1;i++)
		area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
}
const int maxn=310;
Point P[maxn],V[maxn*maxn];
int n,kase;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++) V[i]=P[i]=read_point();
		n--;
		int c=n,e=n;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(SegmentProperIntersection(P[i],P[i+1],P[j],P[j+1]))
					V[c++]=GetLineIntersection(P[i],P[i+1]-P[i],P[j],P[j+1]-P[j]);
		sort(V,V+c);
		c=unique(V,V+c)-V;
		for(int i=0;i<c;i++)
			for(int j=0;j<n;j++)
				if(OnSegment(V[i],P[j],P[j+1])) e++;
		printf("Case %d: There are %d pieces.\n",++kase,e+2-c);
	}
	return 0;
}
