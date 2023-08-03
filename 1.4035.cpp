#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
const int maxn=15;
const double eps=1e-8;
int n;
double a[maxn][maxn],b[maxn],c[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	For(i,1,n+1) For(j,1,n) scanf("%lf",&a[i][j]);
	For(i,1,n) For(j,1,n)
	{
		c[i][j]=2*(a[i][j]-a[i+1][j]);
		b[i]+=a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
	}
	For(i,1,n)
	{
		For(j,i,n)
			if(fabs(c[j][i])>eps)
			{
				For(k,1,n) swap(c[i][k],c[j][k]);
				swap(b[i],b[j]);
				break;
			}
		double d=c[i][i];
		For(j,i,n) c[i][j]/=d; b[i]/=d;
		For(j,1,n)
		{
			if(i==j) continue;
			double r=c[j][i];
			For(k,1,n) c[j][k]-=r*c[i][k]; b[j]-=r*b[i];
		}
	}
	For(i,1,n) printf("%.3lf ",b[i]); printf("\n");
	return 0;
}
