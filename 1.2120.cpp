#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1000005;
int n,Q[maxn],L,R;
LL x[maxn],p[maxn],c[maxn],a[maxn],b[maxn],YY[maxn],XX[maxn],f[maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&x[i],&p[i],&c[i]);
	for(int i=1;i<=n;i++) a[i]=a[i-1]+p[i];
	for(int i=1;i<=n;i++) b[i]=b[i-1]+p[i]*x[i];
	Q[L=R=1]=0;
	for(int i=1;i<=n;i++)
	{
		while(L<R&&YY[Q[L+1]]-YY[Q[L]]<=x[i]*(XX[Q[L+1]]-XX[Q[L]])) L++;
		int j=Q[L];
		f[i]=f[j]+c[i]+x[i]*(a[i]-a[j])-b[i]+b[j];
		XX[i]=a[i];
		YY[i]=f[i]+b[i];
		while(L<R&&(YY[i]-YY[Q[R-1]])*(XX[Q[R]]-XX[Q[R-1]])<=(YY[Q[R]]-YY[Q[R-1]])*(XX[i]-XX[Q[R-1]])) R--;
		Q[++R]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}