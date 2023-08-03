#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
LL x,y,m,n,L,t,r,d;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0) { x=1; y=0; return a; }
	LL d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L);
	d=exgcd(m-n,L,t,r);
	if((y-x)%d) puts("Impossible");
	else printf("%lld\n",((y-x)/d*t%L+L)%L);
	return 0;
}
