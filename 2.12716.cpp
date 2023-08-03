#include<cstdio>
const int maxm=30000000;
int cnt[maxm+1],sum[maxm+1];
inline void init()
{
	for(int c=1;c<=maxm;c++)
		for(int a=c*2;a<=maxm;a+=c)
		{
			int b=a-c;
			if(c==(a^b)) cnt[a]++;
		}
	for(int i=1;i<=maxm;i++) sum[i]=sum[i-1]+cnt[i];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	init();
	int T,n,kase=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("Case %d: %d\n",++kase,sum[n]);
	}
	return 0;
}
