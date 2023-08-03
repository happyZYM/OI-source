#include<cstdio>
#include<cmath>
//C(n,m)=n!/(m!(n-m)!)
const int maxn=200004;
long double logF[maxn*2+1];
inline long double logC(int n,int m)
{
	return logF[n]-logF[m]-logF[n-m];
}
double solve(int n,double p)
{
	double res=0;
	for(int i=0;i<=n;i++)
	{
		long double c=logC(n*2-i,n);
		long double v1=c+(n+1)*log(p)+(n-i)*log(1-p);
		long double v2=c+(n+1)*log(1-p)+(n-i)*log(p);
		res+=i*(exp(v1)+exp(v2));
	}
	return res;
}
int kase=0,n;
double p;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif 
	logF[0]=0;
	for(int i=1;i<=maxn;i++)
		logF[i]=logF[i-1]+log(i);
	while(scanf("%d%lf",&n,&p)==2)
		printf("Case %d: %.6lf\n", ++kase, solve(n, p));
	return 0;
}
