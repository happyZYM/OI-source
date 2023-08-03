#include<cstdio>
#include<cmath>
int n,m;
double res,pos;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2)
	{
		res=0;
		for(int i=1;i<n;i++)
		{
			pos=(double)i/n*(n+m);
			res+=fabs(pos-floor(pos+0.5))/(n+m);
		}
		printf("%.4lf\n",res*10000);
	}
	return 0;
}
