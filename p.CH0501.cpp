//http://contest-hunter.org:83/contest/0x00%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E4%BE%8B%E9%A2%98/0501%20%E8%B4%A7%E4%BB%93%E9%80%89%E5%9D%80
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,a[maxn],v; long long tot=0;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	v=a[n/2];
	for(int i=0;i<n;i++) tot+=abs(v-a[i]);
	printf("%lld\n",tot);
	return 0;
}
