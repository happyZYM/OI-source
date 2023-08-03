//http://contest-hunter.org:83/contest/0x3B%E3%80%8C%E6%95%B0%E5%AD%A6%E7%9F%A5%E8%AF%86%E3%80%8D%E7%BB%83%E4%B9%A0/3B04%20Xiao%209*%E5%A4%A7%E6%88%98%E6%9C%B1%E6%9C%80%E5%AD%A6
#include<cstdio>
#include<cassert>
typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0) { x=1; y=0; return a; }
	LL d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
int n;
LL x,L,t,r,a,m,d;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	scanf("%lld%lld",&m,&a); x=a; L=m;
	for(int i=2;i<=n;i++)
	{
		scanf("%lld%lld",&m,&a);
		d=exgcd(L,m,t,r);
		x+=((a-x)%m+m)%m/d*t*L;
		L=L/d*m;
		x=(x%L+L)%L;
	}
	printf("%lld\n",x);
	return 0;
}
