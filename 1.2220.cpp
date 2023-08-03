#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
const int maxk=100005;
struct Data { int x,y; };
inline bool operator<(const Data &a,const Data &b) { return a.x<b.x||(a.x==b.x&&a.y<b.y); }
inline bool operator==(const Data &a,const Data &b) { return a.x==b.x&&a.y==b.y; }
Data a[maxk];
int n,m,k;
LL ksm(LL a,LL b)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) res=res*a%mod;
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a,a+k);
	k=unique(a,a+k)-a;
	LL v=(LL)n*(n+1)/2%mod,lst=m,sp=1;
	if(k==0) { printf("%lld\n",ksm(v,m)%mod); return 0; }
	else
	{
//		for(int i=0;i<k;i++) printf("a[%d]=(%d,%d)\n",i,a[i].x,a[i].y);
		LL t=(v-a[0].y)%mod; lst--;
		for(int i=1;i<k;i++)
			if(a[i].x==a[i-1].x) (t-=a[i].y)%=mod;
			else
			{
				lst--;
				sp=sp*t%mod;
//				printf("i=%d a[i-1].x=%d t=%lld\n",i,a[i-1].x,t);
				t=(v-a[i].y)%mod;
			}
		sp=sp*t%mod;
//		printf("a[k-1].x=%d t=%lld\n",a[k-1].x,t);
	}
//	printf("v=%lld lst=%lld\n",v,lst);
	printf("%lld\n",(ksm(v,lst)*sp%mod+mod)%mod);
	return 0;
}
