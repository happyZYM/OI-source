#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
template<typename T> inline void read(T& t)
{
    t=0; int ch,f=false;
    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
    if(ch=='-') f=true,ch=getchar();
    t=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+(ch^48);
    if(f) t=-t;
}
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
#define mid ((x+y)>>1)
#define lson (pst<<1)
#define rson (pst<<1|1)
const int maxn=3e5+5,maxm=maxn<<1,inf=0x3f3f3f3f;
int x[maxn],y[maxn],z[maxn],p[maxn];
struct Edge { int v; Edge *next; };
Edge mem[maxm],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; }

int son[maxn],fa[maxn],sz[maxn],dep[maxn],root;
int id[maxn],top[maxn],rak[maxn],dfn;
int c[maxn],d[maxn],srt[maxn];
int ma,mb,mc;
int n,m;

struct BinaryIndexedTree
{
	int a[maxn];
	inline int lowbit(int x) { return x&(-x); }
	inline void update(int x,int k) { for(int i=x;i<=n;i+=lowbit(i)) a[i]+=k; }
	inline int query(int x) { int res=0; for(int i=x;i>=1;i-=lowbit(i)) res+=a[i]; return res; }
	inline void build() { for(int i=1;i<=n;i++) update(i,p[rak[i]]); }
	inline int sum(int l,int r) { return query(r)-query(l-1); }
}BIT;

struct SegmentTree
{
	int val[maxn<<2],tag[maxn<<2];
	inline void pushdown(int pst)
	{
		if(!tag[pst]) return;
		int &k=tag[pst];
		val[lson]=max(val[lson],k); val[rson]=max(val[rson],k);
		tag[lson]=max(tag[lson],k); tag[rson]=max(tag[rson],k);
		k=0;
	}
	inline void pushup(int pst) { val[pst]=max(val[lson],val[rson]); }
	inline void update(int x,int y,int pst,int l,int r,int k)
	{
		if(x>y||y<l||x>r) return;
		if(l<=x&&y<=r) { val[pst]=max(val[pst],k); tag[pst]=max(tag[pst],k); return; }
		pushdown(pst);
		update(x,mid,lson,l,r,k); update(mid+1,y,rson,l,r,k);
		pushup(pst);
	}
	inline int query(int x,int y,int pst,int p)
	{
		if(x==y) return val[pst];
		pushdown(pst);
		if(p<=mid) return query(x,mid,lson,p);
		else return query(mid+1,y,rson,p);
	}
}ST;

inline void dfs1(int u,int f,int d)
{
	fa[u]=f; dep[u]=d; sz[u]=1;
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(v==f) continue;
		dfs1(v,u,d+1);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}

inline void dfs2(int u,int t)
{
	top[u]=t; id[u]=++dfn; rak[id[u]]=u;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(v!=fa[u]&&v!=son[u]) dfs2(v,v);
	}
}

inline int sum(int x,int y)
{
	int tx=top[x],ty=top[y],res=0;
	while(tx!=ty)
	{
		if(dep[tx]>=dep[ty]) { res+=BIT.sum(id[tx],id[x]); x=fa[tx]; tx=top[x]; }
		else { res+=BIT.sum(id[ty],id[y]); y=fa[ty]; ty=top[y]; }
	}
	if(id[x]>id[y]) swap(x,y);
	res+=BIT.sum(id[x]+1,id[y]);
	return res; 
}

inline bool cmp(int x,int y) { return c[x]<c[y]; }
inline void update(int x,int y,int z)
{
	int tx=top[x],ty=top[y],cnt=0;
	while(tx!=ty)
	{
		if(dep[tx]<dep[ty]) { swap(x,y); swap(tx,ty); }
		c[++cnt]=id[tx]; d[cnt]=id[x]; x=fa[tx]; tx=top[x];
	}
	if(id[x]>id[y]) swap(x,y);
	c[++cnt]=id[x]+1; d[cnt]=id[y];
	for(int i=1;i<=cnt;i++) srt[i]=i;
	sort(srt+1,srt+cnt+1,cmp);
	if(c[srt[1]]>1) ST.update(1,n,1,1,c[srt[1]]-1,z);
	if(d[srt[cnt]]<n) ST.update(1,n,1,d[srt[cnt]]+1,n,z);
	for(int i=1;i<cnt;i++) ST.update(1,n,1,d[srt[i]]+1,c[srt[i+1]]-1,z);
}

#define mx(x) (ST.query(1,n,1,id[x]))
int FindAns(int x,int y)
{
	int res=inf;
	if(x==y) return 0;
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) { res=min(res,max(mc-p[x],mx(x))); x=fa[x]; }
	while(x!=y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		res=min(res,max(mc-p[x],mx(x))); x=fa[x];
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n,m);
	for(int i=1;i<n;i++) read(x[i],y[i],z[i]);
	for(int i=1;i<n;i++) { AddEdge(x[i],y[i]); AddEdge(y[i],x[i]); }
	root=rand()%n+1;
	dfs1(root,0,1);
	dfs2(root,root);
	for(int i=1;i<n;i++)
	{
		if(dep[x[i]]>dep[y[i]]) p[x[i]]=z[i];
		else p[y[i]]=z[i];
	}
	BIT.build();
	for(int i=1;i<=m;i++)
	{
		int a,b,tmp; read(a,b);
		tmp=sum(a,b);
		update(a,b,tmp);
		if(tmp>=mc) ma=a,mb=b,mc=tmp;
	}
	printf("%d\n",FindAns(ma,mb));
	return 0;
}
