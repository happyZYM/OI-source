//http://contest-hunter.org:83/contest/0x10%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E4%BE%8B%E9%A2%98/1201%20%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=300005;
LL res,a[maxn],s[maxn];
int n,m,q[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	res=a[1];
	int l=1,r=1; q[1]=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		while(l<=r&&q[l]<i-m) l++;
		res=max(res,s[i]-s[q[l]]);
		while(l<=r&&s[q[r]]>=s[i]) r--;
		q[++r]=i;
	}
	printf("%lld\n",res);
	return 0;
}
