#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long LL;
LL ksm(LL a,LL b,LL p)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%p) b&1?res=res*a%p:0;
	return res;
}
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0) { x=1; y=0; return a; }
	LL d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
int T,K;
void a()
{
	while(T-->0)
	{
		LL y,z,p; scanf("%lld%lld%lld",&y,&z,&p);
		printf("%lld\n",ksm(y,z,p));
	}
}
void b()
{
	while(T-->0)
	{
		LL y,z,p,x,r; scanf("%lld%lld%lld",&y,&z,&p);
		LL d=exgcd(y,p,x,r);
		if(z%d) puts("Orz, I cannot find x!");
		else printf("%lld\n",(z/d*x%p+p)%p);
	}
}
LL BSGS(LL a,LL b,LL p)
{
	b%=p;
	map<LL,int> mp;
	int t=(int)sqrt(p)+1;
	LL x=b,y=ksm(a,t,p);
	if(y==0) return b==0?1:-1;
	for(int j=0;j<=t-1;j++)
	{
		mp[x]=j;
		x=x*a%p;
	}
	x=1;
	for(int i=0,j;i<=t;i++)
	{
		if(mp.find(x)!=mp.end()&&i*t-(j=mp[x])>=0) return i*t-j;
		x=x*y%p;
	}
	return -1;
}
void c()
{
	while(T-->0)
	{
		LL y,z,p; scanf("%lld%lld%lld",&y,&z,&p);
		LL d=BSGS(y,z,p);
		if(d==-1) puts("Orz, I cannot find x!");
		else printf("%lld\n",d);
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&T,&K);
	if(K==1) a();
	else if(K==2) b();
	else c();
	return 0;
}
