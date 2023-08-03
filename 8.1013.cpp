#include<cstdio>
using namespace std;
typedef double LD;
inline LD abs(const LD &x) { return x<0?-x:x; }
inline void swap(LD &a,LD &b) { LD t=a; a=b; b=t; }
int n;
LD a[15][15],b[15][15];
void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++) printf("%.3lf ",b[i][j]);
		puts("");
	}
	puts("");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++) for(int j=1;j<=n;j++) scanf("%lf",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			b[i][j]=2*(a[i][j]-a[i+1][j]);
			b[i][0]+=a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
		}
	for(int i=1;i<=n;i++)
	{
		int pos=i;
		for(int j=i+1;j<=n;j++) if(abs(b[j][i])>abs(b[pos][i])) pos=j;
		for(int j=0;j<=n;j++) swap(b[i][j],b[pos][j]);
		for(int k=1;k<=n;k++) if(k!=i)
		{
			double d=b[k][i]/b[i][i];
			for(int j=i;j<=n;j++) b[k][j]-=d*b[i][j]; b[k][0]-=d*b[i][0];
		}
	}
	for(int i=1;i<n;i++) printf("%.3lf ",b[i][0]/b[i][i]); printf("%.3lf\n",b[n][0]/b[n][n]);
	return 0;
}
