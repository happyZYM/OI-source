#include<cstdio>
typedef long long LL;
LL gcd(LL a,LL b)
{
	return b==0?a:gcd(b,a%b);
}
int n,k,T;
LL a,b;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d",&n,&k);
		b=1ll<<k;
		a=b-k-1;
		LL g=gcd(a,b);
		a/=g;
		b/=g; 
		printf("Case #%d: %lld/%lld\n",i,a,b);
	}
	return 0;
}
