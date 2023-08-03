#include<cstdio>
const int maxn=30005;
const int oo=1e9+7;
inline int max(const int &a,const int &b) { return a>b?a:b; }
#define swap(x,y) x^=y^=x^=y
struct Edge { int v; Edge *next; };
Edge mem[maxn*2],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; } 
int n,m;
int w[maxn],v[maxn],newid[maxn],fa[maxn],top[maxn],dep[maxn],size[maxn],son[maxn];
int dfs_cnt;
namespace Squence
{
	int Sum,Max;
	int setv[maxn<<2],sumv[maxn<<2],maxv[maxn<<2];
	inline void pushdown(int o,int L,int R)
	{
		int M=(L+R)>>1,lc=o<<1,rc=o<<1|1;
		maxv[lc]=setv[lc]=maxv[rc]=setv[rc]=setv[o];
		sumv[lc]=(M-L+1)*setv[o];
		sumv[rc]=(R-M)*setv[o];
		setv[o]=oo;
	}
	void build(int o,int L,int R)
	{
		setv[o]=oo;
		if(L==R) { maxv[o]=sumv[o]=v[L]; return; }
		int M=(L+R)>>1;
		build(o<<1,L,M); build(o<<1|1,M+1,R);
		sumv[o]=sumv[o<<1]+sumv[o<<1|1];
		maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
	}
	void query(int o,int pl,int pr,int L,int R)
	{
		if(L<=pl&&pr<=R) Sum+=sumv[o],Max=max(Max,maxv[o]);
		else
		{
			if(setv[o]<oo) pushdown(o,pl,pr);
			int M=(pl+pr)>>1;
			if(L<=M) query(o<<1,pl,M,L,R);
			if(R>M) query(o<<1|1,M+1,pr,L,R);
		}
	}
	void set(int o,int pl,int pr,int L,int R,int v)
	{
		if(L<=pl&&pr<=R) { maxv[o]=setv[o]=v; sumv[o]=(pr-pl+1)*v; }
		else
		{
			if(setv[o]<oo) pushdown(o,pl,pr);
			int M=(pl+pr)>>1;
			if(L<=M) set(o<<1,pl,M,L,R,v);
			if(R>M) set(o<<1|1,M+1,pr,L,R,v);
			sumv[o]=sumv[o<<1]+sumv[o<<1|1];
			maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
		}
	}
}
void InitData(int u,int f,int dp)
{
	dep[u]=dp; size[u]=1; fa[u]=f;
	int maxson=-1;
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(v==fa[u]) continue;
		InitData(v,u,dp+1);
		size[u]+=size[v];
		if(size[v]>maxson) maxson=size[v],son[u]=v;
	}
}
void AllocId(int u,int topf)
{
	newid[u]=++dfs_cnt; top[u]=topf; v[dfs_cnt]=w[u];
	if(son[u]==0) return;
	AllocId(son[u],topf);
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(v==son[u]||v==fa[u]) continue;
		AllocId(v,v);
	}
}
int qMax(int x,int y)
{
	Squence::Max=w[x];
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		Squence::query(1,1,n,newid[top[x]],newid[x]);
		x=fa[top[x]];
	}
	if(newid[x]>newid[y]) swap(x,y);
	Squence::query(1,1,n,newid[x],newid[y]);
	return Squence::Max;
}
int qSum(int x,int y)
{
	Squence::Sum=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		Squence::query(1,1,n,newid[top[x]],newid[x]);
		x=fa[top[x]];
	}
	if(newid[x]>newid[y]) swap(x,y);
	Squence::query(1,1,n,newid[x],newid[y]);
	return Squence::Sum;
}
int Sum(int x,int y)
{
	Squence::Sum=0;
	Squence::query(1,1,n,x,y);
	return Squence::Sum;
}
int Max(int x,int y)
{
	Squence::Max=0;
	Squence::query(1,1,n,x,y);
	return Squence::Max;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		AddEdge(u,v); AddEdge(v,u);
	}
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	InitData(1,0,1);
	AllocId(1,1);
	Squence::build(1,1,n);
	scanf("%d",&m);
	char cmd[100]; int x,y;
	while(m-->0)
	{
		scanf("%s%d%d",cmd,&x,&y);
		if(cmd[0]=='C')	 Squence::set(1,1,n,newid[x],newid[x],y),w[x]=y;
		else printf("%d\n",cmd[1]=='M'?qMax(x,y):qSum(x,y));
	}
	return 0;
}
/*
5
2 1
3 1
4 1
5 2
4 6 10 9 5 
5
QMAX 2 3
CHANGE 2 7
CHANGE 3 5
QMAX 3 5
CHANGE 3 8
*/
