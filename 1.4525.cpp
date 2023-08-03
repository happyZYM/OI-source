#include<cstdio>
#include<cmath>
double a,b,c,d,L,R;
inline double f(double x) { return (c*x+d)/(a*x+b); }
inline double simpson(double a,double b) { return (f(a)+4*f((a+b)/2)+f(b))*(b-a)/6; }
inline double asr(double a,double b,double eps,double V)
{
	double c=(a+b)/2;
	double L=simpson(a,c),R=simpson(c,b);
	if(fabs(L+R-V)<=15*eps) return L+R+(L+R-V)/15;
	return asr(a,c,eps/2,L)+asr(c,b,eps/2,R);
}
inline double asr(double a,double b,double eps) { return asr(a,b,eps,simpson(a,b)); }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&L,&R);
	printf("%.6lf\n",asr(L,R,1e-6));
	return 0;
}
