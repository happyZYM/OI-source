#include<cstdio>
#define swap(x,y) x^=y^=x^=y
const int maxn=300005;
struct Edge { int v; Edge *next; };
Edge *G[maxn],mem[maxn*2],*ecnt=mem;
inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; }
int n,a[maxn];
int son[maxn],fa[maxn],dep[maxn],size[maxn],top[maxn],newid[maxn],bk[maxn];
int dfs_cnt;
namespace Squence
{
	int sumv[maxn<<2],addv[maxn<<2];
	inline void pushdown(int o,int L,int R)
	{
		int M=(L+R)>>1,lc=o<<1,rc=o<<1|1;
		addv[lc]+=addv[o];
		addv[rc]+=addv[o];
		sumv[lc]+=(M-L+1)*addv[o];
		sumv[rc]+=(R-M)*addv[o];
		addv[o]=0;
	}
	void add(int o,int pl,int pr,int L,int R,int a)
	{
		if(L<=pl&pr<=R) { addv[o]+=a; sumv[o]+=(pr-pl+1)*a; return; }
		else
		{
			pushdown(o,pl,pr);
			int M=(pl+pr)>>1;
			if(L<=M) add(o<<1,pl,M,L,R,a);
			if(R>M) add(o<<1|1,M+1,pr,L,R,a);
			sumv[o]=sumv[o<<1]+sumv[o<<1|1];
		}
	}
}
void InitData(int u,int f,int d)
{
	dep[u]=d; fa[u]=f; size[u]=1;
	int maxson=-1;
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(v==f) continue;
		InitData(v,u,d+1);
		size[u]+=size[v];
		if(size[v]>maxson) maxson=size[v],son[u]=v;
	}
}
void AllocId(int u,int topf)
{
	newid[u]=++dfs_cnt; bk[newid[u]]=u; top[u]=topf;
	if(!son[u]) return;
	AllocId(son[u],topf);
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(v==fa[u]||v==son[u]) continue;
		AllocId(v,v);
	}
}
inline void aPath(int x,int y,int a)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		Squence::add(1,1,n,newid[top[x]],newid[x],a);
		x=fa[top[x]];
	}
	if(newid[x]>newid[y]) swap(x,y);
	Squence::add(1,1,n,newid[x],newid[y],a);
}
int sweet[maxn];
void dfs(int o,int L,int R)
{
	if(L==R) { sweet[bk[L]]+=Squence::sumv[o]; return; }
	Squence::pushdown(o,L,R);
	int M=(L+R)>>1;
	dfs(o<<1,L,M); dfs(o<<1|1,M+1,R);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n-1;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		AddEdge(x,y); AddEdge(y,x);
	}
	InitData(1,0,1);
	AllocId(1,1);
	for(int i=0;i<n-1;i++) aPath(a[i],a[i+1],1);
	dfs(1,1,n);
	for(int i=1;i<n;i++) sweet[a[i]]--;
	for(int i=1;i<=n;i++) printf("%d\n",sweet[i]);
	return 0;
}
/*
5
1 4 5 3 2
1 2
2 4
2 3
4 5
*/
