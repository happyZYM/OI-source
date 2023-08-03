#include<cstdio>
typedef long long LL;
LL a,b,x,y;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0) { x=1; y=0; return a; }
	LL d=exgcd(b,a%b,x,y);
	LL z=x; x=y; y=z-y*(a/b);
	return d;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld",&a,&b);
	exgcd(a,b,x,y);
	printf("%lld %lld\n",x,y);
	return 0;
}
