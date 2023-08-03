#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000000+5;
int n;
int up[maxn],down[maxn];
int h1[maxn],h2[maxn];
int solve()
{
	int level,res=0;
	h1[0]=level=up[0];
	for(int i=1;i<n;i++)
	{
//		int nowup=up[i],nowdown=down[i];
		if(down[i]>level) level=down[i];
		if(up[i]<level) level=up[i];
		h1[i]=level;
	}
	h2[n-1]=level=up[n-1];
	for(int i=n-2;i>=0;i--)
	{
//		int nowup=up[i],nowdown=down[i];
		if(down[i]>level) level=down[i];
		if(up[i]<level) level=up[i];
		h2[i]=level;
	}
	for(int i=0;i<n;i++)
		res+=min(h1[i],h2[i])-down[i];
	return res;
}
int main()
{
	
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",down+i);
		for(int i=0;i<n;i++) scanf("%d",up+i);
		printf("%d\n",solve());
	}
	return 0;
}
