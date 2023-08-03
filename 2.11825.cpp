#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
const int maxn=16;
int n,m,x,kase;
int p[maxn];
int cover[1<<maxn];
int f[1<<maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&m);
			p[i]=1<<i;
			while(m--) { scanf("%d",&x); p[i]|=1<<x; }
		}
		for(int s=0;s<(1<<n);s++)
		{
			cover[s]=0;
			for(int i=0;i<n;i++)
				if(s&(1<<i)) cover[s]|=p[i];
		}
		f[0]=0;
		int ALL=(1<<n)-1;
		for(int s=1;s<(1<<n);s++)
		{
			f[s]=0;
			for(int st=s;st;st=(st-1)&s)
				if(cover[st]==ALL) f[s]=max(f[s],f[s^st]+1);
		}
		printf("Case %d: %d\n",++kase,f[ALL]);
	}
	return 0;
}
