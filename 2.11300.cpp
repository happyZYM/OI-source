#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000010;
long long a[maxn],c[maxn],cnt,M;
int n;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			cnt+=a[i];
		}
		M=cnt/n;
		c[0]=0;
		for(int i=1;i<n;i++) c[i]=c[i-1]+a[i]-M;
		sort(c,c+n);
		long long x=c[n/2],res=0;
		for(int i=0;i<n;i++) res+=abs(x-c[i]);
		printf("%lld\n",res);
	}
	return 0;
}
