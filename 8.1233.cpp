#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,a[maxn],s[maxn],q[maxn],l,r,f[maxn],g[maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	reverse(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	q[l=r=1]=0;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&s[i]>=f[q[l+1]]+s[q[l+1]]) l++;
		f[i]=s[i]-s[q[l]];
		g[i]=g[q[l]]+1;
		while(l<=r&&s[i]+f[i]<=s[q[r]]+f[q[r]]) r--;
		q[++r]=i;
	}
	printf("%d\n",g[n]);
	return 0;
}