//http://contest-hunter.org:83/contest/0x18%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E7%BB%83%E4%B9%A0/1813%20%E5%8F%8C%E6%A0%88%E6%8E%92%E5%BA%8F
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
int T,n,a[maxn],co[maxn],s1[maxn],c1,s2[maxn],c2;
struct JUDGE
{
	int k[maxn];
	struct Edge { int v; Edge *nxt; };
	Edge mem[maxn*maxn*2],*G[maxn],*ecnt;
	inline void init()
	{
		memset(G,0,sizeof(G)); ecnt=mem;
		memset(co,0,sizeof(co));
	}
	inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->nxt=G[u]; G[u]=ecnt++; }
	bool dfs(int u,int c)
	{
		if(co[u]) return co[u]==c;
		co[u]=c;
		for(Edge *it=G[u];it;it=it->nxt) if(!dfs(it->v,3-c)) return false;
		return true;
	}
	bool ok()
	{
		k[n+1]=n+1;
		for(int i=n;i>=1;i--) k[i]=min(k[i+1],a[i]);
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
			if(k[j+1]<a[i]&&a[i]<a[j])
			{
				AddEdge(i,j);
				AddEdge(j,i);
			}
		for(int i=1;i<=n;i++) if(!co[i]&&!dfs(i,1)) return false;
		return true;
	}
}jg;
inline void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	jg.init();
	if(!jg.ok()) { puts("0"); return; }
	int now=1; c1=c2=0;
	for(int i=1;i<=n;i++)
	{
		if(co[i]==1) { s1[c1++]=a[i]; printf("a "); }
		else { s2[c2++]=a[i]; printf("c "); }
		while(true)
		{
			if(c1&&s1[c1-1]==now) { printf("b "); c1--; now++; }
			else if(c2&&s2[c2-1]==now) { printf("d "); c2--; now++; }
			else break;
		}
	}
	puts("");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0) solve();
	return 0;
}
