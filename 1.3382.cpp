#include<cstdio>
#include<cmath>
const double eps=1e-7;
int n;
double L,R,M1,M2,v1,v2,a[14];
inline double cal(double x)
{
	double res=0;
	for(int i=0;i<=n;i++) res=res+a[i]*pow(x,i);
	return res;
}
int main()
{
	scanf("%d%lf%lf",&n,&L,&R);
	for(int i=n;i>=0;i--) scanf("%lf",&a[i]);
	while(R-L>eps)
	{
		M1=(R-L)/3+L; M2=(R-L)/3*2+L;
		v1=cal(M1); v2=cal(M2);
		if(v1>v2) R=M2;
		else if(v1<v2) L=M1;
		else L=M1,R=M2;
	}
	printf("%.5lf\n",L);
	return 0;
}
