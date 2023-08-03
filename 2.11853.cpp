#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1010;
struct Circle
{
	int x,y,r;
	inline void read(){ scanf("%d%d%d",&x,&y,&r); }
}c[N];
double ans1,ans2;
int n,vis[N];
inline bool can(const Circle &a,const Circle &b)
{
	int dx=a.x-b.x;
	int dy=a.y-b.y;
	return dx*dx+dy*dy<=(a.r+b.r)*(a.r+b.r);
}
bool dfs(int u)
{
	vis[u]=1;
	if(c[u].y<=c[u].r) return false;
	if(c[u].x<=c[u].r) ans1=min(ans1,c[u].y-sqrt(c[u].r*c[u].r-c[u].x*c[u].x));
	if(1000<=c[u].x+c[u].r)
		ans2=min(ans2,c[u].y-sqrt(c[u].r*c[u].r-(1000-c[u].x)*(1000-c[u].x)));
	for(int i=0;i<n;i++)
		if(!vis[i]&&can(c[u],c[i])&&!dfs(i))
			return false;
	return true;
}
void solve()
{
	ans1=ans2=1000;
	for(int i=0;i<n;i++)
		if(!vis[i]&&c[i].y+c[i].r>=1000&&!dfs(i))
		{
			puts("IMPOSSIBLE");
			return;
		}
	printf("0.00 %.2lf 1000.00 %.2lf\n",ans1,ans2);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++) c[i].read();
		solve();
	}
	return 0;
}
