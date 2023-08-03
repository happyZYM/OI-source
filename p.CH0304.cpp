//http://contest-hunter.org:83/contest/0x00%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E4%BE%8B%E9%A2%98/0304%20IncDec%20Sequence
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,a[maxn],b[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
	long long p=0,q=0;
	for(int i=2;i<=n;i++)
		if(b[i]>0) p+=b[i];
		else q+=abs(b[i]);
	printf("%lld\n",max(p,q));
	printf("%lld\n",abs(p-q)+1);
	return 0;
}
