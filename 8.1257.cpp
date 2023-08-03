#include<cstdio>
#include<algorithm>
using namespace std;
long long n,k,res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld",&n,&k); res=n*k;
	for(int x=1,gx;x<=n;x=gx+1)
	{
		gx=k/x?min(k/(k/x),n):n;
		res-=(k/x)*(x+gx)*(gx-x+1)/2;
	}
	printf("%lld\n",res);
	return 0;
}
