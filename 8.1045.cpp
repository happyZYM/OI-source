#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1000005;
int n; LL a[maxn],s[maxn],tot;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) { scanf("%lld",&a[i]); tot+=a[i]; }
	tot/=n;
	for(int i=0;i<n;i++) a[i]-=tot;
	s[0]=a[0]; for(int i=1;i<n;i++) s[i]=s[i-1]+a[i];
	sort(s,s+n);
	LL t=s[n/2],res=0;
	for(int i=0;i<n;i++) res+=abs(s[i]-t);
	printf("%lld\n",res);
	return 0;
}
