#include<cstdio>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=128,maxm=11;
int kase,n,m;
char obj[maxn][maxm+100];
int vis[1<<maxm][1<<maxm],d[1<<maxm][1<<maxm];
int cnt[1<<maxm][1<<maxm];
int dp(int s,int a)
{
	if(cnt[s][a]<=1) return 0;
	if(cnt[s][a]==2) return 1;

	int &res=d[s][a],k,s2,a2,need;
	if(vis[s][a]==kase) return res;
	vis[s][a]=kase;
	res=m;
	for(k=0;k<m;k++)
		if(!(s&(1<<k)))
		{
			s2=s|(1<<k),a2=a|(1<<k);
			if(cnt[s2][a2]>=1&&cnt[s2][a]>=1)
			{
				need=max(dp(s2,a2),dp(s2,a))+1;
				res=min(res,need);
			}
		}
	return res;
}
inline void init()
{
	for(int s=0;s<(1<<m);s++)
	{
		for(int a=s;a;a=(a-1)&s)
			cnt[s][a]=0;
		cnt[s][0]=0;
	}
	for(int i=0;i<n;i++)
	{
		int ft=0;
		for(int f=0;f<m;f++)
			if(obj[i][f]=='1') ft|=(1<<f);
		for(int s=0;s<(1<<m);s++)
			cnt[s][s&ft]++;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	memset(vis,0,sizeof(vis));
	while(scanf("%d%d",&m,&n)==2&&n)
	{
		++kase;
		for(int i=0;i<n;i++) scanf("%s",obj[i]);
		init();
		printf("%d\n",dp(0,0));
	}
	return 0;
}
