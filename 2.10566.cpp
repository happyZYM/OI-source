#include<cstdio>
#include<cmath>
double x,y,c,mid;
double cal(double w)
{ return 1-c/sqrt(x*x-w*w)-c/sqrt(y*y-w*w); }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%lf%lf%lf",&x,&y,&c)==3)
	{
		double r,l;
	    r=(x<y?x:y);
		l=0;
		while(l+1e-9<r)
		{
			mid=(l+r)/2;
			if(cal(mid)>0) l=mid;
			else r=mid;
		}
		printf("%.3lf\n",l);
	} 
	return 0;
}
