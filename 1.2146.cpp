#include<cstdio>
#include<cstring>
const int maxn=100005;
struct Edge { int v; Edge *next; };
Edge mem[maxn],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; } 
int n,m;
int w[maxn],v[maxn],newid[maxn],fa[maxn],top[maxn],dep[maxn],size[maxn],son[maxn];
int dfs_cnt;
namespace Squence
{
	int res;
	int setv[maxn<<2],sumv[maxn<<2];
	inline void pushdown(int o,int L,int R)
	{
		int M=(L+R)>>1,lc=o<<1,rc=o<<1|1;
		setv[lc]=setv[rc]=setv[o];
		sumv[lc]=(M-L+1)*setv[o];
		sumv[rc]=(R-M)*setv[o];
		setv[o]=-1;
	}
	void query(int o,int pl,int pr,int L,int R)
	{
		if(L<=pl&&pr<=R) res+=sumv[o];
		else
		{
			if(setv[o]>=0) pushdown(o,pl,pr);
			int M=(pl+pr)>>1;
			if(L<=M) query(o<<1,pl,M,L,R);
			if(R>M) query(o<<1|1,M+1,pr,L,R);
		}
	}
	void set(int o,int pl,int pr,int L,int R,int v)
	{
		if(L<=pl&&pr<=R) { setv[o]=v; sumv[o]=(pr-pl+1)*v; }
		else
		{
			if(setv[o]>=0) pushdown(o,pl,pr);
			int M=(pl+pr)>>1;
			if(L<=M) set(o<<1,pl,M,L,R,v);
			if(R>M) set(o<<1|1,M+1,pr,L,R,v);
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
	if(son[u]==0) return;
	AllocId(son[u],topf);
	for(Edge *it=G[u];it;it=it->next)
	{
		int v=it->v;
		if(v==son[u]||v==fa[u]) continue;
		AllocId(v,v);
	}
}
void install(int x)
{
	int res=0;
	while(x)
	{
		Squence::res=0;
		Squence::query(1,1,n,newid[top[x]],newid[x]);
		res+=dep[x]-dep[top[x]]+1-Squence::res;
		Squence::set(1,1,n,newid[top[x]],newid[x],1);
		x=fa[top[x]];
	}
	printf("%d\n",res);
}
inline void uninstall(int x)
{
	Squence::res=0;
	Squence::query(1,1,n,newid[x],newid[x]+size[x]-1);
	printf("%d\n",Squence::res);
	Squence::set(1,1,n,newid[x],newid[x]+size[x]-1,0);
}
int sum(int L,int R)
{
	Squence::res=0;
	Squence::query(1,1,n,L,R);
	return Squence::res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	int x;
	for(int i=2;i<=n;i++) scanf("%d",&x),AddEdge(x+1,i);
	InitData(1,0,1);
	AllocId(1,1);
	memset(Squence::setv,-1,sizeof(Squence::setv));
	scanf("%d",&m);
	char cmd[50];
	while(m-->0)
	{
		scanf("%s%d",cmd,&x); x++;
		if(cmd[0]=='i') install(x);
		else uninstall(x);
	}
	return 0;
}
/*
7
1 1 1 2 2 6
5
install 6
install 7
uninstall 2
install 5
uninstall 1
*/
