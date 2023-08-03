#include<cstdio>
double a,b,c;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%lf%lf%lf",&a,&b,&c)==3)
		printf("%.5lf\n",(a*b+b*(b-1))/((a+b)*(a+b-c-1)));
	return 0;
}
