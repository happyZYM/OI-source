#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
const int maxn=100005;
struct Edge { int v; Edge *next; };
Edge mem[maxn*2],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; }
int N,Q;
namespace SegmentTree
{
	int mx[maxn<<2];
	void update(int o,int l,int r,int p,int v)
	{
		if(l==r) { mx[o]=v; return; }
		int mid=(l+r)>>1;
		if(p<=mid) update(o<<1,l,mid,p,v);
		else update(o<<1|1,mid+1,r,p,v);
		mx[o]=max(mx[o<<1],mx[o<<1|1]);
	}
	int query(int o,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b) return mx[o];
		int mid=(l+r)>>1,res=0;
		if(a<=mid) res=max(res,query(o<<1,l,mid,a,b));
		if(mid<b) res=max(res,query(o<<1|1,mid+1,r,a,b));
		return res;
	}
}
int dep[maxn],fa[maxn],sz[maxn],son[maxn],id[maxn],rk[maxn],top[maxn],dfn;
const int maxj=18;
void dfs1(int u,int f,int d)
{
	sz[u]=1; fa[u]=f; dep[u]=d;
//	for(int i=0;i<d-1;i++) putchar('\t'); printf("visiting %d\n",u);
	for(Edge *it=G[u];it;it=it->next)
	{
		if(it->v==f) continue;
		dfs1(it->v,u,d+1);
		sz[u]+=sz[it->v];
		if(sz[it->v]>sz[son[u]]) son[u]=it->v; 
	}
}
void dfs2(int u,int t)
{
	assert(!id[u]);
	id[u]=++dfn; top[u]=t; rk[id[u]]=u;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(Edge *it=G[u];it;it=it->next)
	{
		if(it->v==son[u]||it->v==fa[u]) continue;
		dfs2(it->v,it->v);
	}
}
int solve(int x)
{
	int maxid=0;
	while(x!=-1)
	{
//		printf("x=%d top[x]=%d id[x]=%d id[top[x]]=%d\n",x,top[x],id[x],id[top[x]]);
		maxid=max(maxid,SegmentTree::query(1,1,N,id[top[x]],id[x]));
		x=fa[top[x]];
		if(maxid) return rk[maxid];
	}
	return rk[maxid];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N-1;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		AddEdge(u,v); AddEdge(v,u);
	}
	dfs1(1,-1,1);
	dfs2(1,1);
	SegmentTree::update(1,1,N,1,1);
//	for(int i=1;i<=N;i++) printf("dep[%d]=%d fa[%d]=%d sz[%d]=%d son[%d]=%d \n",i,dep[i],i,fa[i],i,sz[i],i,son[i]);
	while(Q-->0)
	{
		char opt; int x;
		scanf("%s %d",&opt,&x);
//		printf("%c %d\n",opt,x);
		if(opt=='C') SegmentTree::update(1,1,N,id[x],id[x]);
		else printf("%d\n",solve(x));
	}
	return 0;
}
