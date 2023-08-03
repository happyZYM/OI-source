#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long LL;
LL a,b,p;
LL ksm(LL a,LL b,LL p)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) res=res*a%p;
	return res;
}
LL solve()
{
	map<LL,int> mp;
	LL m=sqrt(p)+1,c_j=1;
	for(int i=0;i<m;i++)
	{
		if(mp.find(c_j)==mp.end()) mp[c_j]=i;
		c_j=c_j*a%p;
	}
	LL a__m=ksm(a,p-1-m,p),c_i=b;
	for(int i=0;i<m;i++)
	{
		if(mp.find(c_i)!=mp.end()) return i*m+mp[c_i];
		c_i=c_i*a__m%p;
	}
	return -1;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld\n",solve());
	return 0;
}
