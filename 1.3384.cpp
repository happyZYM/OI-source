#include<cstdio>
#define swap(x,y) x^=y^=x^=y
template<typename T>
inline void read(T& t)
{
    t=0; bool f=false; char ch;
    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
    if(ch=='-') f=true,ch=getchar();
    t=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+ch-'0';
    if(f) t=-t;
}
template<typename T,typename... Args>
inline void read(T& t,Args&... args) { read(t); read(args...); }

const int maxn=200010;
struct Edge { int v; Edge *next; };
Edge *G[maxn],mem[maxn],*ecnt=mem;
inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; }
int n,m,r,mod;
int son[maxn],fa[maxn],dep[maxn],size[maxn],top[maxn],v[maxn],w[maxn],newid[maxn];
int dfs_cnt;
namespace Squence
{
	int sumv[maxn<<2],addv[maxn<<2];
	int res;
	inline void pushdown(int o,int L,int R)
	{
		int M=(L+R)>>1,lc=o<<1,rc=o<<1|1;
		addv[lc]=(addv[lc]+addv[o])%mod;
		addv[rc]=(addv[rc]+addv[o])%mod;
		sumv[lc]=(sumv[lc]+(M-L+1)*addv[o])%mod;
		sumv[rc]=(sumv[rc]+(R-M)*addv[o])%mod;
		addv[o]=0;
	}
	void build(int o,int L,int R)
	{
		if(L==R) { sumv[o]=w[L]; return; }
		int M=(L+R)>>1;
		build(o<<1,L,M); build(o<<1|1,M+1,R);
		sumv[o]=(sumv[o<<1]+sumv[o<<1|1])%mod;
	}
	void query(int o,int pl,int pr,int L,int R)
	{
		if(L<=pl&&pr<=R) { res=(res+sumv[o])%mod; return; }
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
		if(L<=pl&pr<=R) { addv[o]=(addv[o]+a)%mod; sumv[o]=(sumv[o]+(pr-pl+1)*a)%mod; return; }
		else
		{
			pushdown(o,pl,pr);
			int M=(pl+pr)>>1;
			if(L<=M) add(o<<1,pl,M,L,R,a);
			if(R>M) add(o<<1|1,M+1,pr,L,R,a);
			sumv[o]=(sumv[o<<1]+sumv[o<<1|1])%mod;
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
	newid[u]=++dfs_cnt; w[dfs_cnt]=v[u]; top[u]=topf;
	if(!son[u]) return;
	AllocId(son[u],topf);
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(v==fa[u]||v==son[u]) continue;
		AllocId(v,v);
	}
}
inline int qSub(int o)
{
	Squence::res=0;
	Squence::query(1,1,n,newid[o],newid[o]+size[o]-1);
	return Squence::res;
}
inline void aSub(int o,int a) { Squence::add(1,1,n,newid[o],newid[o]+size[o]-1,a); }
inline int qPath(int x,int y)
{
	int res=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		Squence::res=0;
		Squence::query(1,1,n,newid[top[x]],newid[x]);
		res=(res+Squence::res)%mod;
		x=fa[top[x]];
	}
	if(newid[x]>newid[y]) swap(x,y);
	Squence::res=0;
	Squence::query(1,1,n,newid[x],newid[y]);
	res=(res+Squence::res)%mod;
	return res;
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
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n,m,r,mod);
	for(int i=1;i<=n;i++) read(v[i]);
	for(int i=0;i<n-1;i++)
	{
		int x,y; read(x,y);
		AddEdge(x,y); AddEdge(y,x);
	}
	InitData(r,0,1);
	AllocId(r,r);
	Squence::build(1,1,n);
	int opt,x,y,z;
	while(m-->0)
	{
		read(opt);
		if(opt==1) read(x,y,z),aPath(x,y,z);
		else if(opt==2) read(x,y),printf("%d\n",qPath(x,y));
		else if(opt==3) read(x,z),aSub(x,z);
		else if(opt==4) read(x),printf("%d\n",qSub(x));
	}
	return 0;
}
