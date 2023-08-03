#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct Point
{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y) { }
	inline bool operator<(const Point &b) { return x<b.x||(x==b.x&&y<b.y); }
};
typedef Point Vector;
inline Vector operator+(const Vector &a,const Vector &b) { return Vector(a.x+b.x,a.y+b.y); }
inline Vector operator-(const Vector &a,const Vector &b) { return Vector(a.x-b.x,a.y-b.y); }
inline Vector operator*(const Vector &a,double b) { return Vector(a.x*b,a.y*b); }
inline Vector operator/(const Vector &a,double b) { return Vector(a.x/b,a.y/b); }
inline double Dot(const Vector &a,const Vector &b) { return a.x*b.x+a.y*b.y; }
inline double Cross(const Vector &a,const Vector &b) { return a.x*b.y-a.y*b.x; }
inline double Length(const Vector &a) { return sqrt(Dot(a,a)); }
const double eps=1e-6;
inline int dcmp(double x) { return fabs(x)<eps?0:(x>0?1:-1); }
inline double PolygonArea(Point *p,int n)
{
	double area=0;
	for(int i=1;i<n-1;i++) area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
}

struct Line
{
	Point P; Vector v; double ang;
	Line(Point P=Point(),Vector v=Vector()):P(P),v(v) { ang=atan2(v.y,v.x); }
	inline bool operator<(const Line &b) const { return ang<b.ang; }
};

inline bool OnLeft(const Line &L,const Point &p) { return dcmp(Cross(L.v,p-L.P))>0; }

inline Point GetLineIntersection(const Line &a,const Line &b)
{
	Vector u=a.P-b.P;
	double t=Cross(b.v,u)/Cross(a.v,b.v);
	return a.P+a.v*t;
}

int HalfplaneIntersection(Line *L,int n,Point *poly)
{
	sort(L,L+n);
	int head,tail;
	Point *p=new Point[n];
	Line *q=new Line[n];
	q[head=tail=0]=L[0];
	for(int i=1;i<n;i++)
	{
		while(head<tail&&!OnLeft(L[i],p[tail-1])) tail--;
		while(head<tail&&!OnLeft(L[i],p[head])) head++;
		q[++tail]=L[i];
		if(dcmp(Cross(q[tail].v,q[tail-1].v))==0)
		{
			tail--;
			if(OnLeft(q[tail],L[i].P)) q[tail]=L[i];
		}
		if(head<tail) p[tail-1]=GetLineIntersection(q[tail-1],q[tail]);
	}
	while(head<tail&&!OnLeft(q[head],p[tail-1])) tail--;
	if(tail-head<=1) return 0;
	p[tail]=GetLineIntersection(q[tail],q[head]);
	
	int m=0;
	for(int i=head;i<=tail;i++) poly[m++]=p[i];
	return m;
}

const int maxn=25;
const int maxedge=10*50+7;
int n,m;
Point poly[maxn],res[maxedge];
Line L[maxedge]; int cnt;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		for(int j=0;j<m;j++) scanf("%lf%lf",&poly[j].x,&poly[j].y);
		for(int j=0;j<m;j++) L[cnt++]=Line(poly[j],poly[(j+1)%m]-poly[j]);
	}
	int reslen=HalfplaneIntersection(L,cnt,res);
	double ans=0;
	if(reslen>=3) ans=PolygonArea(res,reslen);
	printf("%.3lf\n",ans);
	return 0;
}
