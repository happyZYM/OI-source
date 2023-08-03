//http://contest-hunter.org:83/contest/0x30%E3%80%8C%E6%95%B0%E5%AD%A6%E7%9F%A5%E8%AF%86%E3%80%8D%E4%BE%8B%E9%A2%98/3101%20%E9%98%B6%E4%B9%98%E5%88%86%E8%A7%A3
#include<cstdio>
const int maxn=1e6+5;
int n,p[maxn],v[maxn],cnt;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) v[i]=i;
	for(int i=2;i<=n;i++)
	{
		if(v[i]==i) p[cnt++]=i;
		for(int j=0;j<cnt&&p[j]*i<=n&&p[j]<=v[i];j++) v[p[j]*i]=p[j];
	}
	for(int i=0;i<cnt;i++)
	{
		long long tot=0,x=p[i];
		while(x<=n) { tot+=n/x; x*=p[i]; }
		printf("%d %d\n",p[i],tot);
	}
	return 0;
}
