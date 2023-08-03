#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define x first
#define y second
typedef long long LL;
const LL mod=1000000007;
const int maxn=2010;
pair<int,int> a[maxn];
int h,w,n;
LL f[maxn],jc[200010],ijc[200010];
inline LL C(int n,int m) { return jc[n]*ijc[m]%mod*ijc[n-m]%mod; }
inline LL ksm(LL a,LL b)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%mod) b&1?res=res*a%mod:0;
	return res;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	jc[0]=1; ijc[0]=1;
	for(int i=1;i<=200000;i++) { jc[i]=jc[i-1]*i%mod; ijc[i]=ksm(jc[i],mod-2); }
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n);
	a[n+1].x=h; a[n+1].y=w;
	for(int i=1;i<=n+1;i++)
	{
		f[i]=C(a[i].x+a[i].y-2,a[i].x-1);
		for(int j=1;j<i;j++)
		{
			if(a[j].x>a[i].x||a[j].y>a[i].y) continue;
			f[i]=(f[i]-(LL)f[j]*C(a[i].x+a[i].y-a[j].x-a[j].y,a[i].x-a[j].x))%mod;
			f[i]=f[i]<0?f[i]+mod:f[i];
		}
	}
	printf("%lld\n",f[n+1]);
	return 0;
}