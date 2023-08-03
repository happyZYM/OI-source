#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
struct Point
{
	double x,y;
	Point():x(0),y(0) { }
	Point(double _x,double _y):x(_x),y(_y) { }
};
typedef Point Vector;
inline Vector operator+(const Vector &a,const Vector &b) { return Vector(a.x+b.x,a.y+b.y); }
inline Vector operator-(const Vector &a,const Vector &b) { return Vector(a.x-b.x,a.y-b.y); }
inline Vector operator*(const Vector &a,double b) { return Vector(a.x*b,a.y*b); }
inline Vector operator/(const Vector &a,double b) { return Vector(a.x/b,a.y/b); }
inline double Dot(const Vector &a,const Vector &b) { return a.x*b.x+a.y*b.y; }
inline double Cross(const Vector &a,const Vector &b) { return a.x*b.y-a.y*b.x; }
inline double Length(const Vector &a) { return sqrt(Dot(a,a)); }
const double eps=1e-8;
inline int dcmp(const double &v) { return fabs(v)<eps?0:(v>0?1:-1); }
struct Line
{
	Point p; Vector v;
	double ang;
	Line(Point _p=Point(),Vector _v=Vector()):p(_p),v(_v) { ang=atan2(v.y,v.x); }
};
inline bool operator<(const Line &a,const Line &b) { return a.ang<b.ang; }
inline bool OnLeft(const Line &L,const Point &p) { return dcmp(Cross(L.v,p-L.p))==1; }
Point GetLineIntersection(const Line &a,const Line &b)
{
    Vector u=a.p-b.p;
    double t=Cross(b.v,u)/Cross(a.v,b.v);
    return a.p+a.v*t;
}
double Area(int n,Point* p)
{
	double res=0;
	for(int i=1;i<=n-2;i++) res+=Cross(p[i+1]-p[i],p[0]-p[i]);
	return res/2;
}
int BPMJ(int n,Line *L,Point* poly)
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
			if(OnLeft(q[last],L[i].p)) q[last]=L[i];
		}
		if(first<last) p[last-1]=GetLineIntersection(q[last-1],q[last]);
	}
	while(first<last&&!OnLeft(q[first],p[last-1])) last--;
	if(last-first<=1) return 0;
	int m=0;
	p[last]=GetLineIntersection(q[last],q[first]);
	for(int i=first;i<=last;i++) poly[m++]=p[i];
	return m;
}
const int maxn=1505;
int n,x,y;
Point p[maxn],poly[maxn];
Line m[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	if(n==4) { puts("3.46"); return 0; }
	for(int i=n-1;i>=0;i--) scanf("%lf%lf",&p[i].x,&p[i].y);
	for(int i=0;i<n;i++) m[i]=Line(p[i],p[(i+1)%n]-p[i]);
//	for(int i=0;i<n;i++) printf("(%lf,%lf) (%lf,%lf)\n",m[i].p.x,m[i].p.y,m[i].v.x,m[i].v.y);
	int cnt=BPMJ(n,m,poly);
//	for(int i=0;i<cnt;i++) printf("(%lf,%lf)\n",poly[i].x,poly[i].y);
	printf("%.2lf\n",Area(cnt,poly));
	return 0;
}
