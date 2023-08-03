#include<cstdio>
typedef long long LL;
const int maxn=100005;
struct Edge { int v; Edge *next; };
Edge mem[maxn*2],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; } 
int n,m;
int w[maxn],v[maxn],newid[maxn],fa[maxn],top[maxn],dep[maxn],size[maxn],son[maxn];
int dfs_cnt;
namespace Squence
{
	LL res;
	LL addv[maxn<<2],sumv[maxn<<2];
	inline void pushdown(int o,int L,int R)
	{
		int M=(L+R)>>1,lc=o<<1,rc=o<<1|1;
		addv[lc]+=addv[o];
		addv[rc]+=addv[o];
		sumv[lc]+=(M-L+1)*addv[o];
		sumv[rc]+=(R-M)*addv[o];
		addv[o]=0;
	}
	void build(int o,int L,int R)
	{
		if(L==R) { sumv[o]=v[L]; return; }
		int M=(L+R)>>1;
		build(o<<1,L,M); build(o<<1|1,M+1,R);
		sumv[o]=sumv[o<<1]+sumv[o<<1|1]; 
	}
	void query(int o,int pl,int pr,int L,int R)
	{
		if(L<=pl&&pr<=R) res+=sumv[o];
		else
		{
			pushdown(o,pl,pr);
			int M=(pl+pr)>>1;
			if(L<=M) query(o<<1,pl,M,L,R);
			if(R>M) query(o<<1|1,M+1,pr,L,R);
		}
	}
	void add(int o,int pl,int pr,int L,int R,int a)
	{
		if(L<=pl&&pr<=R) { addv[o]+=a; sumv[o]+=(LL)(pr-pl+1)*a; }
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
	if(!son[u]) return;
	AllocId(son[u],topf);
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(v==son[u]||v==fa[u]) continue;
		AllocId(v,v);
	}
}
inline void AddNode(int x,int a)
{
	Squence::add(1,1,n,newid[x],newid[x],a);
}
inline void AddSub(int x,int a)
{
	Squence::add(1,1,n,newid[x],newid[x]+size[x]-1,a);
}
inline LL qPath(int x)
{
	LL res=0;
	while(x)
	{
		Squence::res=0;
		Squence::query(1,1,n,newid[top[x]],newid[x]);
		res+=Squence::res;
		x=fa[top[x]];
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=0;i<n-1;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		AddEdge(u,v); AddEdge(v,u);
	}
	InitData(1,0,1);
	AllocId(1,1);
	Squence::build(1,1,n);
	int opt,x,a;
	while(m-->0)
	{
		scanf("%d",&opt);
		if(opt==1) scanf("%d%d",&x,&a),AddNode(x,a);
		if(opt==2) scanf("%d%d",&x,&a),AddSub(x,a);
		if(opt==3) scanf("%d",&x),printf("%lld\n",qPath(x));
	}
	return 0;
}
