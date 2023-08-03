#include<cstdio>
#include<cmath> 
using namespace std;
struct Point
{
	double x,y,r;
};
double line(Point a)
{
	a.x=abs(a.x);
	a.y=abs(a.y);
	double s=sqrt(a.x*a.x+a.y*a.y);
	double ans=s/50.0*2;
	ans+=a.r*1.5;
	return ans;
}
int main()
{
	double ans=0;
	int n;
	scanf("%d",&n);
	Point wu[n];
	for(int i=0;i<n;i++) scanf("%lf%lf%lf",&wu[i].x,&wu[i].y,&wu[i].r);
	for(int i=0;i<n;i++) ans+=line(wu[i]);
	ans=ceil(ans);
	printf("%.0lf\n",ans);
	return 0;
}
