#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=500005;
int T,n,m,Q[maxn],L,R;
LL a[maxn],s[maxn],f[maxn],X[maxn],Y[maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		Q[L=R=1]=0;
		X[0]=1;
		for(int i=m;i<=2*m-1&&i<=n;i++)
		{
			f[i]=s[i]-i*a[1];
			X[i]=a[i+1];
			Y[i]=f[i]-s[i]+i*a[i+1];
		}
		for(int i=2*m;i<=n;i++)
		{
			int p=i-m;
			while(L<R&&(Y[Q[R]]-Y[Q[R-1]])*(X[p]-X[Q[R-1]])>=(Y[p]-Y[Q[R-1]])*(X[Q[R]]-X[Q[R-1]])) R--;
			Q[++R]=p;
			while(L<R&&(Y[Q[L+1]]-Y[Q[L]])<=i*(X[Q[L+1]]-X[Q[L]])) L++;
			int j=Q[L];
			f[i]=f[j]+s[i]-s[j]-(i-j)*a[j+1];
			X[i]=a[i+1];
			Y[i]=f[i]-s[i]+i*a[i+1];
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}