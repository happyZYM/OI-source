#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[1005];
bool dfs(int d,int maxd)
{
	if(d>maxd) return false;
	if(a[d]==n) return true;
	int maxn=0;
	for(int i=0;i<d+1;i++) maxn=max(maxn,a[i]);
	if((maxn<<(maxd-d))<n) return false;
	for(int i=d;i>=0;i--)
	{
		a[d+1]=a[d]+a[i];
		if(dfs(d+1,maxd)) return true;
		a[d+1]=a[d]-a[i];
		if(dfs(d+1,maxd)) return true;
	}
	return false;
}
int solve()
{
	a[0]=1;
	for(int i=0;i<=1005;i++)
		if(dfs(0,i)) return i;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n) printf("%d\n",solve());
	return 0;
}
