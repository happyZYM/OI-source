#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10005;
const int maxm=50005;
const int oo=0x3f3f3f3f;
struct Edge { int v,w; Edge *next; };
Edge mem[maxm*2],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->next=G[u]; G[u]=ecnt++; } 
int n,m,q;
namespace LinkSet
{
	int fa[maxn];
	void init() { for(int i=1;i<=n;i++) fa[i]=i; }
	int ff(int x)
	{
		int a=x,b;
		while(x!=fa[x]) x=fa[x];
		while(a!=x)
		{
			b=fa[a];
			fa[a]=x;
			a=b;
		}
		return x;
	}
}
namespace Kruskal
{
	struct EDGE { int u,v,w; };
	inline bool operator<(const EDGE &a,const EDGE &b) { return a.w>b.w; }
	vector<EDGE> e;
	inline void AddEdge(int u,int v,int w) { e.push_back((EDGE){u,v,w}); }
	void kruskal()
	{
		using namespace LinkSet;
		sort(e.begin(),e.end());
		int cnt=0,es=e.size();
		for(int i=0;i<es&&cnt<n-1;i++)
		{
			int x=e[i].u,y=e[i].v,fx=ff(x),fy=ff(y);
			if(fx==fy) continue;
			fa[fx]=fy; cnt++;
			::AddEdge(x,y,e[i].w); ::AddEdge(y,x,e[i].w);
		}
	}
}
bool vis[maxn];
int f[maxn][21],w[maxn][21],deep[maxn];
void dfs(int u,int fa)
{
	vis[u]=true;
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(v==fa) continue;
		f[v][0]=u;
		w[v][0]=it->w;
		deep[v]=deep[u]+1;
		dfs(v,u);
	}
}
int GetLCA(int x,int y)
{
	using namespace LinkSet;
	if(ff(x)!=ff(y)) return -1;
	int res=oo;
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=20;i>=0;i--)
		if(deep[f[x][i]]>=deep[y])
		{
			res=min(res,w[x][i]);
			x=f[x][i];
		}
	if(x==y) return res;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i])
		{
			res=min(res,min(w[x][i],w[y][i]));
			x=f[x][i];
			y=f[y][i];
		}
	res=min(res,min(w[x][0],w[y][0]));
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	while(m-->0)
	{
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		Kruskal::AddEdge(x,y,z);
	}
	LinkSet::init();
	Kruskal::kruskal();
	memset(w,0x3f,sizeof(w));
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			deep[i]=1;
			dfs(i,-1);
		}
	for(int i=1;i<=20;i++)
		for(int j=1;j<=n;j++)
		{
			f[j][i]=f[f[j][i-1]][i-1];
			w[j][i]=min(w[j][i-1],w[f[j][i-1]][i-1]);
		}
	scanf("%d",&q);
	while(q-->0)
	{
		int x,y; scanf("%d%d",&x,&y);
		printf("%d\n",GetLCA(x,y));
	}
	return 0;
}
