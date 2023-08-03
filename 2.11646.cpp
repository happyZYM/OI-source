#include<cstdio>
#include<cmath>
int m,n,kase;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    while(scanf("%d : %d", &m, &n)==2)
	{
        double k=(double)n/m;
        double a=200/(1+atan(k)*sqrt(1+k*k));
        double b=a*k;
        printf("Case %d: %.10lf %.10lf\n",++kase,a,b);
    }
    return 0;
}
