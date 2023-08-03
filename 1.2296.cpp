#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=10005;
const int maxm=200005;
const int oo=0x3f3f3f3f;
struct Graph
{
	struct Edge { int v; Edge *next; };
	Edge mem[maxm],*G[maxn],*ecnt;
	Graph() { ecnt=mem; }
	inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; } 
};
Graph G,inv;
int n,m,x,y,s,t;
int d[maxn]; bool can[maxn],valid[maxn],vis[maxn];
void init()
{
	valid[t]=true;
	queue<int> Q;
	Q.push(t); vis[t]=true;
	while(Q.size())
	{
		int u=Q.front(); Q.pop();
		for(Graph::Edge *it=inv.G[u];it;it=it->next)
			if(!vis[it->v])
			{
				Q.push(it->v);
				vis[it->v]=true; valid[it->v]=true;
			}
	}
	for(int i=1;i<=n;i++)
	{
		can[i]=(G.G[i]!=0);
		if(!can[i]) continue;
		for(Graph::Edge *it=G.G[i];it;it=it->next)
			if(!valid[it->v])
			{
				can[i]=false;
				break;
			}
	}
	can[t]=true;
}
struct Node { int u,dis; };
inline bool operator<(const Node &a,const Node &b) { return a.dis>b.dis; }
int dijskra()
{
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	if(!can[s]) return -1;
	d[s]=0;
	priority_queue<Node> Q;
	Q.push(Node{s,0});
	while(Q.size())
	{
		int u=Q.top().u,dis=Q.top().dis; Q.pop();
		if(vis[u]) continue;
		for(Graph::Edge *it=G.G[u];it;it=it->next)
			if(can[it->v]&&dis+1<d[it->v])
			{
				d[it->v]=dis+1;
				Q.push(Node{it->v,d[it->v]});
			}
	}
	return d[t]<oo?d[t]:-1;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	while(m-->0)
	{
		scanf("%d%d",&x,&y);
		G.AddEdge(x,y); inv.AddEdge(y,x);
	}
	scanf("%d%d",&s,&t);
	init();
//	for(int i=1;i<=n;i++) printf("valid[%d]=%d ",i,valid[i]); printf("\n");
//	for(int i=1;i<=n;i++) printf("can[%d]=%d ",i,can[i]); printf("\n");
	printf("%d\n",dijskra());
	return 0;
}
