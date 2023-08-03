#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cassert>
using std::max;
typedef long long LL;
const int maxn=1000100;
bool hsh[maxn];
LL prime[maxn],cnt;
LL a[maxn];
void solve(int L,int R)
{
	memset(hsh,true,sizeof(hsh));
	for(int i=0;i<cnt&&prime[i]*prime[i];i++)
	{
		int s=L/prime[i]+(L%prime[i]?1:0);
		s=(s<2?2:s);
		for(LL j=s*prime[i];j<=R;j+=prime[i]) hsh[j-L]=false;
	}
	int top=0;
	for(LL i=L;i<=R;i++) if(hsh[i-L]&&i!=1) a[top++]=i;
	if(top<2) { printf("There are no adjacent primes.\n"); return; }
	LL Min=2147483647ll,p1=0; LL Max=0,p2=0;
	for(int i=0;i<top-1;i++)
	{
		if(a[i+1]-a[i]<Min) Min=a[i+1]-a[i],p1=i;
		if(a[i+1]-a[i]>Max) Max=a[i+1]-a[i],p2=i;
	}
	printf("%lld,%lld are closest, %lld,%lld are most distant.\n",a[p1],a[p1+1],a[p2],a[p2+1]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	memset(hsh,true,sizeof(hsh));
	for(int i=2;i<maxn;i++)
	{
		if(hsh[i]) prime[cnt++]=i;
		for(int j=0;j<cnt&&prime[j]*i<maxn;j++)
		{
			hsh[prime[j]*i]=false;
			if(i%prime[j]==0) break;
		}
	}
	LL L,R;
	while(scanf("%lld%lld",&L,&R)==2) solve(L,R);
	return 0;
}
