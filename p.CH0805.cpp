//http://contest-hunter.org:83/contest/0x08%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E7%BB%83%E4%B9%A0/0805%20%E9%98%B2%E7%BA%BF%EF%BC%88%E7%A7%A6%E8%85%BE%E4%B8%8E%E6%95%99%E5%AD%A6%E8%AF%84%E4%BC%B0%EF%BC%89
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=200005;
int T,n;
LL s[maxn],e[maxn],d[maxn],maxe;
inline LL sum(LL p)
{
	LL tot=0;
	for(int i=0;i<n;i++) if(min(e[i],p)>=s[i]) tot+=(min(e[i],p)-s[i])/d[i]+1;
	return tot;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		maxe=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld%lld\n",&s[i],&e[i],&d[i]);
			maxe=max(maxe,e[i]);
		}
		LL L=0,R=maxe+1,M,res=maxe+1;
		while(L<=R)
		{
			M=(L+R)>>1;
			if(sum(M)&1) res=M,R=M-1;
			else L=M+1;
		}
		if(res==maxe+1) puts("There's no weakness.");
		else printf("%lld %lld\n",res,sum(res)-sum(res-1));
	}
	return 0;
}
