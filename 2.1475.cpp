#include<cstdio>
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

const double ops=1e-10;
inline int dcmp(double x)
{ return (x>0?x:-x)<ops?0:(x>0?1:-1); }

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

struct Line
{
	Point P;
	Vector v;
	double ang;
	Line(Point P=Point(),Vector v=Vector()):P(P),v(v) { ang=atan2(v.y,v.x); }
	inline bool operator<(const Line &L) const
	{ return ang<L.ang; }
};

inline bool OnLeft(const Line &L,const Point &p)
{ return dcmp(Cross(L.v,p-L.P))>0; }

Point GetLineIntersection(const Line &a,const Line &b)
{
	Vector u=a.P-b.P;
	double t=Cross(b.v,u)/Cross(a.v,b.v);
	return a.P+a.v*t;
}

int HalfplaneIntersection(Line *L,int n)
{
	sort(L,L+n);
	int first,last;
	Point *p=new Point[n];
	Line *q=new Line[n];
	q[first=last=0]=L[0];
	for(int i=1;i<n;i++)
	{
		while(first<last&&!OnLeft(L[i],p[last-1])) last--;
		while(first<last&&!OnLeft(L[i],p[first])) first++;
		q[++last]=L[i];
		if(dcmp(Cross(q[last].v,q[last-1].v))==0)
		{
			last--;
			if(OnLeft(q[last],L[i].P)) q[last]=L[i];
		}
		if(first<last) p[last-1]=GetLineIntersection(q[last-1],q[last]);
	}
	while(first<last&&!OnLeft(q[first],p[last-1])) last--;
	if(last-first<=1) return 0;
	p[last]=GetLineIntersection(q[last],q[first]);
	
	return max(last-first+1,0);
}
const int maxn=50005;
int n;
Point p[maxn];
Line L[maxn];
bool check(int x)
{
	if(x==n) return true;
	for(int i=0;i<n;i++) L[i]=Line(p[i],p[(i+x+1)%n]-p[i]);
	return !HalfplaneIntersection(L,n);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		for(int i=n-1;i>=0;i--) scanf("%lf%lf",&p[i].x,&p[i].y);
		int L=0,R=n,res;
		while(L<=R)
		{
			int mid=(L+R)/2;
			if(check(mid)) res=mid,R=mid-1;
			else L=mid+1;
		}
		printf("%d\n",res);
	}
	return 0;
}
