#include<cstdio>
#include<algorithm>
#include<cassert>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int maxn=405;
const LL mod=1e9+7;
inline LL ksm(LL a,LL b)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) res=res*a%mod;
	return res;
}
int n,m;
LL a[maxn][maxn*2];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n); m=n*2;
	For(i,1,n)
	{
		For(j,1,n) scanf("%lld",&a[i][j]);
		a[i][i+n]=1;
	}
	For(i,1,n)
	{
		For(j,i,n)
			if(a[j][i])
			{
				For(k,1,m) swap(a[i][k],a[j][k]);
				break;
			}
		if(!a[i][i]) return puts("No Solution"),0;
		LL inv=ksm(a[i][i],mod-2);
		For(j,i,m) a[i][j]=a[i][j]*inv%mod;
		For(j,1,n) if(i!=j)
		{
			LL r=a[j][i];
			For(k,i,m) a[j][k]=((a[j][k]-r*a[i][k])%mod+mod)%mod;
		}
	}
	For(i,1,n)
	{
		For(j,1+n,m) printf("%lld ",a[i][j]);
		printf("\n");+ 
	}
	return 0;
}
