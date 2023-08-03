#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double Pi=acos(-1);
int n,r;
double res,g[505];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&r)==2&&n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&g[i]);
			g[i]=g[i]/180*Pi;
		}
		sort(g,g+n);
		res=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				res+=(n+2*i-2*j)*sin(g[j]-g[i]);
		res=res*r*r/2;
		printf("%.0lf\n",res);
	}
	return 0;
}
