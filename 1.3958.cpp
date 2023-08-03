#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1005;
int T,n,h; LL r;
LL x[maxn],y[maxn],z[maxn];
struct Edge { int v; Edge *next; };
Edge mem[maxn*maxn],*G[maxn],*ecnt;
bool vis[maxn];
bool solve()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j
			&&(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j])<=4*r*r)
			{
				ecnt->v=j; ecnt->next=G[i]; G[i]=ecnt++;
			}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&z[i]<=r)
		{
			vis[i]=true;
			queue<int> Q;
			Q.push(i);
			while(Q.size())
			{
				int u=Q.front(); Q.pop();
				if(z[u]>=h-r) return true;
				for(Edge *it=G[u];it;it=it->next)
					if(!vis[it->v])
					{
						vis[it->v]=true;
						Q.push(it->v);
					}
			}
		}
	return false;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		ecnt=mem; memset(vis,0,sizeof(vis)); memset(G,0,sizeof(G));
		scanf("%d%d%lld",&n,&h,&r);
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		if(solve()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
