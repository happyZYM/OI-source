#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL maxn=65536;
const LL maxm=1e6+5;
LL L,R,p[maxn],v[maxn],pcnt;
bool flg[maxm]; LL tot,num[maxm];
void solve()
{
	memset(flg,1,sizeof(flg));
	for(LL i=0;i<pcnt&&p[i]<=R;i++)
		for(LL j=max(L/p[i],2ll);j<=R/p[i]+1;j++)
			if(L<=p[i]*j&&p[i]*j<=R) flg[p[i]*j-L]=0;
	if(L==1) flg[0]=0;
	tot=0;
	for(LL i=L;i<=R;i++) if(flg[i-L]) num[tot++]=i;
	if(tot<2) { puts("There are no adjacent primes."); return; }
	LL la=num[0],ra=num[1],lb=num[0],rb=num[1];
	for(LL i=1;i<tot-1;i++)
	{
		if(num[i+1]-num[i]<ra-la) la=num[i],ra=num[i+1];
		if(num[i+1]-num[i]>rb-lb) lb=num[i],rb=num[i+1];
	}
	printf("%lld,%lld are closest, %lld,%lld are most distant.\n",la,ra,lb,rb);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(LL i=1;i<maxn;i++) v[i]=i;
	for(LL i=2;i<maxn;i++)
	{
		if(v[i]==i) p[pcnt++]=i;
		for(LL j=0;j<pcnt&&p[j]*i<maxn&&p[j]<=v[i];j++) v[p[j]*i]=p[j];
	}
	while(scanf("%lld%lld",&L,&R)==2) solve();
	return 0;
}
