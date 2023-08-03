#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0) { x=1; y=0; return a; }
	LL d=exgcd(b,a%b,x,y);
	LL z=x; x=y; y=z-(a/b)*y;
	return d;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	LL a,b,x,y;
	scanf("%lld%lld",&a,&b);
	exgcd(a,b,x,y);
	printf("%lld\n",(x%b+b)%b);
	return 0;
}
