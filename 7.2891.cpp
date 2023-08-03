#include<cstdio>
typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(!b) { x=1; y=0; return a; }
	LL d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
int n,fail;
LL a,m,lcm,res,k,d,x,y;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%lld%lld",&n,&m,&a)==3)
	{
		lcm=m; res=a; fail=0;
		//printf("lcm=%d now=%d\n",lcm,res);
		for(int i=2;i<=n;i++)
		{
			scanf("%lld%lld",&m,&a);
			a=(a-res%m+m)%m;// printf("i=%d a=%d\n",i,a);
			d=exgcd(lcm,m,x,y);// printf("d=%d x=%d y=%d\n",d,x,y);
			if(a%d) fail=1;
			else k=x*(a/d)%m;
			res=res+k*lcm;
			lcm=lcm/d*m;
			res=(res%lcm+lcm)%lcm;
		}
		printf("%lld\n",fail?-1:res);
	}
	return 0;
}
