//http://contest-hunter.org:83/contest/0x20%E3%80%8C%E6%90%9C%E7%B4%A2%E3%80%8D%E4%BE%8B%E9%A2%98/2201%20%E5%B0%8F%E7%8C%AB%E7%88%AC%E5%B1%B1
#include<cstdio>
#include<algorithm>
using namespace std;
int n,w,l[20],c[20],res,cnt=0;
void dfs(int d)
{
	if(cnt>=res) return;
	if(d==n)
	{
		res=cnt;
		return;
	}
	for(int i=0;i<cnt;i++) if(l[i]+c[d]<=w)
	{
		l[i]+=c[d];
		dfs(d+1);
		l[i]-=c[d];
	}
	l[cnt++]=c[d];
	dfs(d+1);
	l[--cnt]=0;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&w);
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	res=n;
	sort(c,c+n); reverse(c,c+n);
	dfs(0);
	printf("%d\n",res);
	return 0;
}
