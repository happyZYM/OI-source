#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=65536;
int p[maxn],v[maxn],ph[maxn],cnt;
LL n,res;
inline int phi(int x)
{
	LL res=x;
	for(LL i=2;i*i<=x;i++) if(x%i==0)
	{
		res=res/i*(i-1);
		while(x%i==0) x/=i;
	}
	if(x>1) res=res/x*(x-1);
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	/*
	ph[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!v[i]) { v[i]=i; ph[i]=i-1; p[cnt++]=i; }
		for(int j=0;j<cnt&&(long long)p[j]*i<maxn&&p[j]<=v[i];j++)
		{
			v[p[j]*i]=p[j];
			ph[p[j]*i]=ph[i]*(p[j]<v[i]?p[j]-1:p[j]);
		}
	}
	*/
	while(scanf("%d",&n)==1)
	{
		res=0;
		for(LL i=1;i*i<=n;i++) if(n%i==0)
		{
			res+=i*phi(n/i);
			if(i*i<n) res+=n/i*phi(i);
		}
		printf("%lld\n",res);
	}
	return 0;
}
