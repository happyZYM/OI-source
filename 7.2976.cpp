#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
const double eps=1e-8;
int n,k,a[maxn],b[maxn];
double c[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&k)==2&&n)
	{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		double L=0,R=1,M;
		for(int i=0;i<100;i++)
		{
			M=(L+R)/2;
			for(int j=1;j<=n;j++) c[j]=a[j]-b[j]*M;
			sort(c+1,c+1+n);
			double res=0;
			for(int j=k+1;j<=n;j++) res+=c[j];
			if(res>eps) L=M;
			else R=M;
		}
		printf("%.0lf\n",(L+R)*50);
	}
	return 0;
}
