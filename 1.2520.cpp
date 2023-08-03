#include<cstdio>
typedef long long LL;
LL T,a,b,x,y,c;
LL gcd(LL a,LL b) { return b==0?a:gcd(b,a%b); }
inline bool chk(LL x,LL y) { return x%c==0&&y%c==0; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld",&T);
	while(T-->0)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
		c=2*gcd(a,b);
		if(a==0&&b==0&&!(x==0&&y==0)) { puts("N"); continue; }
		if(chk(x,y)||chk(x+a,y+b)||chk(x+b,y+a)||chk(x+a+b,y+a+b)) puts("Y");
		else puts("N");
	}
	return 0;
}
