#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-10;
const int N=1e5;
inline int dcmp(double x)
{ return fabs(x)<eps?0:(x>0?1:-1); }
struct point
{
	double x,y;
	point() { }
	point(double x,double y):x(x),y(y){}
	inline point operator+(const point &a) const
	{ return point(x+a.x,y+a.y); }
	inline point operator-(const point &a) const
	{ return point(x-a.x,y-a.y); }
	inline void in() { scanf("%lf%lf",&x,&y); }
	inline bool operator < (const point &a) const
	{ return x+eps<a.x||(!dcmp(x-a.x)&&y<a.y); }
};
inline double dot(point a,point b)
{ return a.x*b.x+a.y*b.y; }
inline double cross(point a,point b)
{ return a.x*b.y-a.y*b.x; }
bool SegmentProperIntersectiom(point a1,point a2,point b1,point b2)
{
	double c1=cross(a2-a1,b1-a1),c2=cross(a2-a1,b2-a1),
		   c3=cross(b2-b1,a1-b1),c4=cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<=0&&dcmp(c3)*dcmp(c4)<=0;
}
bool OnSegment(point p,point a1,point a2)
{
	return dcmp(cross(a1-p,a2-p))==0&&dcmp(dot(a1-p,a2-p))<0;
}
int isPointInpolygon(point p,point *ch,int n)
{
	int wn=0;
	for(int i=0;i<n;i++)
	{
		if(OnSegment(p,ch[i],ch[(i+1)%n])) return 1;
		int k=dcmp(cross(ch[(i+1)%n]-ch[i],p-ch[i]));
		int d1=dcmp(ch[i].y-p.y);
		int d2=dcmp(ch[(i+1)%n].y-p.y);
		if(k>0&&d1<=0&&d2>0) wn++;
		if(k<0&&d2<=0&&d1>0) wn--;
	}
	if(wn!=0) return 1;
	return 0;
}
int ConvexHull(point *p,int n,point *ch)
{
	sort(p,p+n);
	int m=0;
	for(int i=0;i<n;i++)
	{
		while(m>1&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--)
	{
		while(m>k&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	}
	if(n>1) m--;
	return m;
}
int m,c;
point p1[510],p2[510],ch1[510],ch2[510];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&m,&c)==2&&!(m==0&&c==0))
	{
		for(int i=0;i<m;i++) p1[i].in();
		for(int i=0;i<c;i++) p2[i].in();
		int n1=ConvexHull(p1,m,ch1);
		int n2=ConvexHull(p2,c,ch2);
		int flag=1;
		for(int i=0;i<n1;i++)
			if(isPointInpolygon(ch1[i],ch2,n2)) { flag=0; break; }
		for(int i=0;i<n2;i++)
			if(isPointInpolygon(ch2[i],ch1,n1)) { flag=0; break; }
		ch1[n1]=ch1[0];
		ch2[n2]=ch2[0];
		for(int i=0;i<n1;i++)
		{
			for(int j=0;j<n2;j++)
			{
				if(SegmentProperIntersectiom(ch1[i],ch1[i+1],ch2[j],ch2[j+1]))
				{
					flag=0;
					break;
				}
			}
			if(flag==0) break;
		}
		printf("%s\n",flag?"Yes":"No");
	}
	return 0;
}
