#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cassert>
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
inline bool SIT(const Point &a1,const Point &a2,const Point &b1,const Point &b2)
{
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
		   c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
inline Point LIT(const Point &P,const Vector &v,const Point &Q,const Vector &w)
{
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;
}

const int maxn=105;
int n,kase;
double x[maxn*3+maxn*maxn];
Point L[maxn][2][2];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		int c=0; double res=0;
		for(int i=0;i<n;i++)
		{
			double X,H,B;
			scanf("%lf%lf%lf",&X,&H,&B);
			L[i][0][0]=Point(X-B*0.5,0);
			L[i][0][1]=L[i][1][0]=Point(X,H);
			L[i][1][1]=Point(X+B*0.5,0);
			x[c++]=X-B*0.5; x[c++]=X; x[c++]=X+B*0.5;
		}
#ifdef debug
		printf("Points:\n");
		for(int i=0;i<n;i++)
			printf("(%g,%g)\n(%g,%g)\n(%g,%g)\n"
				,L[i][0][0].x,L[i][0][0].y
				,L[i][0][1].x,L[i][0][1].y
				,L[i][1][1].x,L[i][1][1].y);
		printf("\n");
#endif
		for(int i=0;i<n;i++) for(int a=0;a<2;a++)
			for(int j=i+1;j<n;j++) for(int b=0;b<2;b++)
			{
				Point &P1=L[i][a][0],&P2=L[i][a][1],&P3=L[j][b][0],&P4=L[j][b][1];
				if(SIT(P1,P2,P3,P4))
				{
					x[c++]=LIT(P1,P2-P1,P3,P4-P3).x;
					double nowx=x[c-1];
					assert(P1.x<=P2.x);
					assert(P3.x<=P4.x);
					assert(P1.x<=nowx&&nowx<=P2.x);
					assert(P3.x<=nowx&&nowx<=P4.x);
				}
			}
		sort(x,x+c);
		c=unique(x,x+c)-x;
		Point l=Point(x[0],0);
#ifdef debug
		printf("x:\n");
		for(int i=0;i<c;i++) printf("%.5lf\n",x[i]);
		printf("\n");
#endif
		for(int i=1;i<c;i++)
		{
			Point r=Point(x[i],0);
			double lx=x[i-1],rx=x[i];
			for(int j=0;j<n;j++) for(int a=0;a<2;a++)
			{
				Point &P1=L[j][a][0],&P2=L[j][a][1];
				assert(P1.x<=P2.x);
				if(P1.x<=lx&&lx<=P2.x&&P1.x<=rx&&rx<=P2.x)
				{
					Vector v=P2-P1;
					Point tr=P1+v*(rx-P1.x)/(P2.x-P1.x);
					if(tr.y>=r.y) r=tr;
				}
			}
			l.y=max(l.y,0.0);
			if(dcmp(l.y)||dcmp(r.y))
			{
				res+=Length(r-l);
#ifdef debug
				printf("i=%d res+=%.5lf l=(%.5lf,%.5lf) r=(%.5lf,%.5lf)\n"
					,i,Length(r-l)
					,l.x,l.y
					,r.x,r.y);
				assert(dcmp(r.x-x[i])==0);
				assert(dcmp(r.y+1));
#endif
			}
#ifdef debug
			printf("after i=%d res is %.5lf\n",i,res);
			printf("\n");
#endif
			l=r;
		}
		printf("Case %d: %.0lf\n\n",++kase,res);
	}
	return 0;
}
/*
1
100 50 100
3
20  30  35
37 24   29
60 20 13
0
*/
