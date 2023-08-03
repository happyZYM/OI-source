#include<cstdio>
#include<cstring>
#include<queue>
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
const int maxn=100005;
const int maxm=200005;
int T;
int N,M,K,P;
struct Edge { int v,w; Edge *next; };
struct Graph
{
	Edge mem[maxm*2],*G[maxn],*ecnt;
	inline void init() { memset(G,0,sizeof(G)); ecnt=mem; } 
	inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->next=G[u]; G[u]=ecnt++; }
};
Graph G,inv;
struct Node { int u,dis; };
inline bool operator<(const Node &a,const Node &b) { return a.dis>b.dis; } 
int d[maxn],vis[maxn];
void dijstra()
{
	memset(vis,0,sizeof(vis)); memset(d,0x3f,sizeof(d));
	d[N]=0;
	priority_queue<Node> Q;
	Q.push((Node){N,0});
	while(Q.size())
	{
		int u=Q.top().u,dis=Q.top().dis; Q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(Edge *it=inv.G[u];it;it=it->next)
			if(d[it->v]>dis+it->w)
			{
				d[it->v]=dis+it->w;
				Q.push((Node){it->v,d[it->v]});
			}
	}
}
int in[maxn][55],f[maxn][55];
int dfs(int u,int k)
{
	if(in[u][k]) return -1;
	if(f[u][k]) return f[u][k];
	in[u][k]=true; if(u==N) f[u][k]=1;
	for(Edge *it=G.G[u];it;it=it->next)
	{
		int tp,v,w;
		if((tp=d[v=it->v]-d[u]+it->w)<=k)
		{
			if((w=dfs(v,k-tp))==-1) return f[u][k]=-1;
			f[u][k]=(f[u][k]+w)%P;
		}
	}
	in[u][k]=0;
	return f[u][k];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		read(N,M,K,P);
		G.init(); inv.init();
		while(M-->0)
		{
			int u,v,w; read(u,v,w);
			G.AddEdge(u,v,w); inv.AddEdge(v,u,w);
		}
		dijstra();
		memset(in,0,sizeof(in)); memset(f,0,sizeof(f));
		printf("%d\n",dfs(1,K));
	}
	return 0;
}
