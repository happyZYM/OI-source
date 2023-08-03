#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
LL n,x[maxn],r[maxn],L,R,M1,M2,v1,v2,res;
inline LL f(LL p)
{
	LL tot=0;
	for(int i=1;i<=n;i++) tot+=abs(p-x[i])*r[i];
//	printf("p=%lld tot=%lld\n",p,tot);
	return tot;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld",&R,&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&r[i]);
	res=f(0);
	while(R-L>3)
	{
		M1=(R-L)/3+L; M2=(R-L)/3*2+L;
		v1=f(M1); v2=f(M2);
		if(v1>=v2) L=M1,res=v2;
		else R=M2,res=v1;
	}
	for(LL i=L;i<=R;i++) res=min(res,f(i));
	printf("%lld\n",res);
	return 0;
}
