#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1000005;
int n,Q[maxn],L,R;
LL a,b,c,v[maxn],s[maxn],X[maxn],Y[maxn],f[maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%lld%lld%lld",&n,&a,&b,&c);
	for(int i=1;i<=n;i++) scanf("%lld",&v[i]);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+v[i];
	Q[L=R=1]=0;
	for(int i=1;i<=n;i++)
	{
		while(L<R&&(Y[Q[L+1]]-Y[Q[L]])>=2*a*s[i]*(X[Q[L+1]]-X[Q[L]])) L++;
		int j=Q[L];
		f[i]=f[j]+a*(s[i]-s[j])*(s[i]-s[j])+b*(s[i]-s[j])+c;
		X[i]=s[i]; Y[i]=f[i]+a*s[i]*s[i]-b*s[i];
		while(L<R&&(Y[Q[R]]-Y[Q[R-1]])*(X[i]-X[Q[R-1]])<=(Y[i]-Y[Q[R-1]])*(X[Q[R]]-X[Q[R-1]])) R--;
		Q[++R]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}