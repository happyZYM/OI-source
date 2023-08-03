#include<cstdio>
#include<cmath>
int T;
double a,b,s,ans,m;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lf%lf%lf",&a,&b,&s);
		m=a*b;
		if(fabs(s)<1e-6) ans=1;
		else if(s>m) ans=0;
		else ans=(m-s-s*log(m/s))/m;
		printf("%.6lf%%\n",ans*100);
	}
	return 0;
}
