#include<cstdio>
#include<cmath>
double a;
inline double f(double x) { return pow(x,a/x-x); }
inline double simpson(double a,double b) { return (f(a)+4*f((a+b)/2)+f(b))*(b-a)/6; }
double asr(double a,double b,double eps,double A)
{
	double c=(a+b)/2;
	double L=simpson(a,c),R=simpson(c,b);
	if(fabs(L+R-A)<=15*eps) return L+R+(L+R-A)/15;
	return asr(a,c,eps/2,L)+asr(c,b,eps/2,R);
}
double asr(double a,double b,double eps) { return asr(a,b,eps,simpson(a,b)); }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lf",&a);
	const double eps=1e-8;
	if(a<0) printf("orz\n");
	else printf("%.5lf\n",asr(eps,20,eps));
	return 0;
}
