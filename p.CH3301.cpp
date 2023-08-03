//http://contest-hunter.org:83/contest/0x30%E3%80%8C%E6%95%B0%E5%AD%A6%E7%9F%A5%E8%AF%86%E3%80%8D%E4%BE%8B%E9%A2%98/3301%20%E5%90%8C%E4%BD%99%E6%96%B9%E7%A8%8B
#include<cstdio>
typedef long long LL;
LL a,b,x,y;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(!b) { x=1; y=0; return a; }
	LL d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&a,&b);
	exgcd(a,b,x,y);
	printf("%d\n",(x+b)%b);
	return 0;
}
