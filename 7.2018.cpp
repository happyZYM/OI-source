#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
const double eps=1e-5;
double a[maxn],b[maxn],s[maxn];
int n,L;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
	double l=-1e6,r=1e6;
	while(r-l>eps)
	{
		double m=(l+r)/2,res=-1e10,mv=1e0;
		for(int i=1;i<=n;i++) b[i]=a[i]-m;
		for(int i=1;i<=n;i++) s[i]=b[i]+s[i-1];
		for(int i=L;i<=n;i++)
		{
			mv=min(mv,s[i-L]);
			res=max(res,s[i]-mv);
		}
		if(res>=0) l=m;
		else r=m;
	}
	printf("%d\n",int(r*1000));
	return 0;
}
