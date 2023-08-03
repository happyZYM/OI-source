#include<cstdio>
#include<cmath>
inline void swap(double &a,double &b) { double t=a; a=b; b=t; }
const double eps=1E-8;
double a[110][110];
int n;
#define For(i,a,b) for(int i=a;i<=b;i++)
int main()
{
    scanf("%d",&n);
    For(i,0,n-1) For(j,0,n) scanf("%lf",&a[i][j]);
    for(int i=0;i<n;i++)
	{
        int pos=i;
        for(int j=i+1;j<n;j++) if(fabs(a[pos][i])<fabs(a[i][j])) pos=j;
        for(int j=0;j<=n;j++) swap(a[i][j],a[pos][j]);
        if(fabs(a[i][i])<=eps) return printf("No Solution\n"),0;
        for(int j=i+1;j<=n;j++) a[i][j]/=a[i][i];
        for(int j=0;j<n;j++)
            if(i!=j)
                for(int k=i+1;k<=n;k++) a[j][k]-=a[j][i]*a[i][k];
    }
    for(int i=0;i<n;i++) printf("%.2lf\n",a[i][n]);
    return 0;
}
