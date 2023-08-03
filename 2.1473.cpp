#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
const double EPS=1e-9;
using namespace std;
const int MAXN=10010;
const double PI=acos(-1.0);
struct point
{ double x,y; };
int N;
point P[MAXN];
int dcmp(double a)
{
	return fabs(a)<EPS?0:(a<0?-1:1);
}
double GetH(double R)
{
	double maxH=0.0;
	for(int i=0;i<N;++i)
	{
		double tmp=R*P[i].y/(R-P[i].x);
		if(dcmp(tmp-maxH)>0) maxH=tmp;
	}
	return maxH;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&N)==1)
	{
		double maxR=0.0;
		for(int i=0;i<N;i++)
		{
			double x,y,z;
			scanf("%lf%lf%lf",&x,&y,&z);
			P[i].x=sqrt(x*x+y*y);
			P[i].y=z;
			maxR=max(maxR,P[i].x);
		}
		double low=maxR,high=1e10;
		while(dcmp(high-low)>0)
		{
			double mid=(low+high)/2.0;
			double midmid=(mid+high)/2.0;
			double midV=GetH(mid)*mid*mid;
			double midmidV=GetH(midmid)*midmid*midmid;
			if(dcmp(midV-midmidV)<=0) high=midmid;
			else low=mid;
		}
		printf("%.3f %.3f\n",GetH(low),low);
	}
	return 0;
}
