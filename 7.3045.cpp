#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=50005;
struct COW { int w,s; };
int n; COW co[maxn];
inline bool operator<(const COW &a,const COW &b) { return a.w+a.s<b.w+b.s; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d",&co[i].w,&co[i].s);
	sort(co,co+n);
	LL sum=0,res=-1e9;
	for(int i=0;i<n;i++)
	{
		if(sum-co[i].s>res) res=sum-co[i].s;
		sum+=co[i].w;
	}
	printf("%lld\n",res);
	return 0;
}
