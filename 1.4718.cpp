#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int ps[]={2,3,5,7,11,13,17,19,23,29,31,37};
const int pcnt=sizeof(ps)/sizeof(int);
inline LL mt(LL a,LL b,LL m)
{
	LL d=((long double)a/m*b+1e-8);
	LL r=a*b-d*m;
	return r<0?r+m:r;
}
inline LL mpow(LL a,LL b,LL m)
{
	LL res=1;
	for(;b;b>>=1,a=mt(a,a,m)) if(b&1) res=mt(res,a,m);
	return res;
}
inline LL gcd(LL a,LL b)
{
	if(!a||!b) return a+b;
	int t=__builtin_ctzll(a|b);
	a>>=__builtin_ctzll(a);
	do
	{
		b>>=__builtin_ctzll(b);
		if(a>b) { LL t=b; b=a; a=t; }
		b-=a;
	}
	while(b!=0);
	return a<<t;
}
inline int isp(LL n)
{
	if(n==1) return 0;
	if(n==2||n==3||n==5) return 1;
	if(!(n&1)||(n%3==0)||(n%5==0)) return 0;
	LL m=n-1; int k=0;
	while(!(m&1)) m>>=1,++k;
	for(int i=0;i<pcnt&&ps[i]<n;++i)
	{
		LL x=mpow(ps[i],m,n),y=x;
		for(int i=0;i<k;i++)
		{
			x=mt(x,x,n);
			if(x==1&&y!=1&&y!=n-1) return 0;
			y=x;
		}
		if(x!=1) return 0;
	}
	return 1;
}
LL f[105],cnt;
inline LL nxt(LL x,LL n,LL a)
{
	x=mt(x,x,n)+a;
	return x<n?x:x-n;
}
const int M=(1<<7)-1;
inline LL rho(LL n)
{
	if(n%2==0) return 2; if(n%3==0) return 3;
	LL x=0,y=0,t=1,q=1,a=(rand()%(n-1))+1;
	for(int k=2;true;k<<=1,y=x,q=1)
	{
		for(int i=1;i<k;++i)
		{
			x=nxt(x,n,a);
			q=mt(q,abs(x-y),n);
			if(!(i&M))
			{
				t=gcd(q,n);
				if(t>1) break;
			}
		}
		if(t>1||(t=gcd(q,n))>1) break;
	}
	if(t==n) for(t=1;t==n;t=gcd(abs((x=nxt(x,n,a))-y),n));
	return t;
}
void solve(LL n)
{
	if(n==1) return;
	if(isp(n)) { f[cnt++]=n; return; }
	LL t=n; while(t==n) t=rho(n); 
	solve(t); solve(n/t);
}
int main()
{
	int T; LL n;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%lld",&n);
		cnt=0; solve(n); sort(f,f+cnt);
		if(cnt==1) puts("Prime");
		else printf("%lld\n",f[cnt-1]);
	}
	return 0;
}
