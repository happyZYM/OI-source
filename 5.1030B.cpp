#include<cstdio>
struct Point
{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y) { }
};
typedef Point Vector;
inline Vector operator+(const Vector &a,const Vector &b) { return Vector(a.x+b.x,a.y+b.y); }
inline Vector operator-(const Vector &a,const Vector &b) { return Vector(a.x-b.x,a.y-b.y); }
inline double Cross(const Vector &a,const Vector &b) { return a.x*b.y-a.y*b.x; }
int n,d,m,x,y;
inline bool OnLeft(const Point &O,const Vector &v,const Point &P) { return Cross(v,P-O)>=0; }
Point a1,a2,a3,a4;
Vector v1,v2,v3,v4;
inline bool in(int x,int y)
{
	Point p(x,y);
	return OnLeft(a1,v1,p)&&OnLeft(a2,v2,p)&&OnLeft(a3,v3,p)&&OnLeft(a4,v4,p);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&d,&m);
	a1=Point(d,0);
	a2=Point(n,n-d);
	a3=Point(n-d,n);
	a4=Point(0,d);
	v1=a2-a1;
	v2=a3-a2;
	v3=a4-a3;
	v4=a1-a4;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		if(in(x,y)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
