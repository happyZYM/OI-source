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
int T,n,m;
double sumx,sumy,res;
Point p[10005],ch[10005];
double X1,Y1,X2,Y2;
double A,B,C;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d",&n);
		sumx=0;sumy=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			sumx+=p[i].x;
			sumy+=p[i].y;
		}
		m=ConvexHull(p,n,ch);
		res=1e20;
		if(m<=2) res=0;
		else for(int i=0;i<m;i++)
		{
			X1=ch[i].x;Y1=ch[i].y;X2=ch[(i+1)%m].x;Y2=ch[(i+1)%m].y;
			A=Y2-Y1;
			B=X1-X2;
			C=X2*Y1-X1*Y2;
			res=min(res,fabs(A*sumx+B*sumy+C*n)/sqrt(A*A+B*B));
		}
		printf("Case #%d: %.3lf\n",kase,res/n);
	}
	return 0;
}
