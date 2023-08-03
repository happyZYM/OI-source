#include<cstdio>
#include<algorithm>
using std::sort;
typedef long long LL;
const int maxn=10005;
int n,x[maxn],y[maxn];
inline LL abs(const LL &x) { return x>0?x:-x; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++) x[i]+=1-i;
	sort(x+1,x+n+1); sort(y+1,y+n+1);
	LL res=0,tx=x[(n+1)/2],ty=y[(n+1)/2];
	for(int i=1;i<=n;i++) res+=abs(x[i]-tx)+abs(y[i]-ty);
	printf("%lld\n",res);
	return 0;
}
