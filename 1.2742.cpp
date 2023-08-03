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
inline double Dot(const Vector &a,const Vector &b) { return a.x*b.x+a.y*b.y; }
inline double Cross(const Vector &a,const Vector &b) { return a.x*b.y-a.y*b.x; }
inline double Length(const Vector &a) { return sqrt(Dot(a,a)); }
const double eps=1e-6;
inline int dcmp(double x) { return fabs(x)<eps?0:(x>0?1:-1); }

const int maxn=10005;
int n; Point p[maxn],res[maxn];
int ConvexHull(Point *p,int n,Point *res)
{
	sort(p,p+n);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		while(cnt>=2&&dcmp(Cross(res[cnt-1]-res[cnt-2],p[i]-res[cnt-1]))<=0) cnt--;
		res[cnt++]=p[i];
	}
	int k=cnt;
	for(int i=n-2;i>=0;i--)
	{
		while(cnt>k&&dcmp(Cross(res[cnt-1]-res[cnt-2],p[i]-res[cnt-1]))<=0) cnt--;
		res[cnt++]=p[i];
	}
	if(n>1) cnt--;
	return cnt;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
	int size=ConvexHull(p,n,res);
	double ans=0;
	for(int i=0;i<size;i++) ans+=Length(res[i]-res[(i+1)%n]);
	printf("%.2lf\n",ans);
	return 0;
}
