#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
typedef long long LL;
LL g,p,A,B,a,b,n,m,inv;
map<LL,int> mp;
inline LL ksm(LL a,LL b) { LL res=1; for(;b;b>>=1,a=a*a%p) b&1?res=res*a%p:0; return res; }
inline LL BSGS(LL A,LL B)
{
	A%=p; B%=p;
	for(int i=0;i<m;i++)
	{
		if(mp[B]) return (i*m+mp[B])%p;
		B=B*inv%p;
	}
	return -1;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld%lld",&g,&p,&n);
	m=ceil(sqrt(p));
	LL x=1;
	for(int i=1;i<=m;i++)
	{
		x=x*g%p;
		mp[x]=i;
	}
	inv=ksm(g,p-m-1)%p;
	while(n-->0)
	{
		scanf("%lld%lld",&A,&B);
		//printf("a=%d b=%d\n",a,b);
		printf("%lld\n",ksm(B,BSGS(g,A))%p);
	}
	return 0;
}
