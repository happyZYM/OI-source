#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,k,res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld",&n,&k); res=n*k;
	for(int l=1,r;l<=n;l=r+1)
	{
		r=k/l?min(k/(k/l),n):n;
		res-=(k/l)*(l+r)*(r-l+1)/2;
	}
	printf("%lld\n",res);
	return 0;
}
