//http://contest-hunter.org:83/contest/0x10%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E4%BE%8B%E9%A2%98/1602%20The%20XOR%20Largest%20Pair
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxmem=1e5*32+5;
const int maxn=1e5+5;
int n,a[maxn],G[maxmem][2],cnt;
inline void insert(int x)
{
	int p=0;
	for(int i=30;i>=0;i--)
	{
		int now=(x>>i)&1;
		if(!G[p][now]) G[p][now]=++cnt;
		p=G[p][now];
	}
}
inline int query(int x)
{
	int p=0,res=0;
	for(int i=30;i>=0;i--)
	{
		int now=(x>>i)&1;
		if(G[p][now^1]) { p=G[p][now^1]; res+=1<<i; }
		else p=G[p][now];
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) insert(a[i]);
	int res=0;
	for(int i=0;i<n;i++) res=max(res,query(a[i]));
	printf("%d\n",res);
	return 0;
}
