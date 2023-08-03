#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=105;
int n,kase;
int x[maxn],y[maxn],z[maxn],r[maxn];
double d[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n!=-1)
	{
		for(int i=1;i<=n;i++) scanf("%d%d%d%d",x+i,y+i,z+i,r+i);
		for(int i=n+1;i<=n+2;i++)
		{
			scanf("%d%d%d",x+i,y+i,z+i);
			r[i]=0;
		}
		n+=2;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=max(0.0,sqrt((x[i]-x[j])*(x[i]-x[j])
									+(y[i]-y[j])*(y[i]-y[j])
									+(z[i]-z[j])*(z[i]-z[j]))
								-r[i]-r[j]);
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		printf("Cheese %d: Travel time = %.0lf sec\n",++kase,d[n-1][n]*10);
	}
	return 0;
}
