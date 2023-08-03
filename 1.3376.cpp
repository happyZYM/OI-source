#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm> 
using namespace std;
const int oo=1e9+7;
const int maxn=10005;
const int maxm=100005;
namespace HLPP
{
	struct Edge { int v,cap,next; };
	int n,s,t;
	int h[maxn],cnt[maxn],prs[maxn];
	struct cmp { inline bool operator()(int a,int b) { return h[a]<h[b]; } };
	Edge e[maxm*2]; int G[maxn],ecnt=1;
	priority_queue<int,vector<int>,cmp> Q;
	inline void AddEdge(int from,int to,int cap)
	{
		e[++ecnt]=(Edge){to,cap,G[from]}; G[from]=ecnt;
		e[++ecnt]=(Edge){from,0,G[to]}; G[to]=ecnt;
	}
	inline bool push(int u,int v,int p)
	{
		int flow=min(prs[u],e[p].cap);
		e[p].cap-=flow; e[p^1].cap+=flow;
		prs[u]-=flow; prs[v]+=flow;
		return flow;
	}
	inline void Gap(int l)
	{ for(int i=1;i<=n;i++) if(i!=s&&i!=t&&l<h[i]&&h[i]<=n) h[i]=n+1;  }
	int Maxflow(int n,int s,int t)
	{
		HLPP::s=s; HLPP::t=t; HLPP::n=n;
		h[s]=n; prs[s]=oo; Q.push(s);
		while(Q.size())
		{
			int u=Q.top(); Q.pop();
			if(!prs[u]) continue;
			for(int i=G[u],v=e[i].v;i;i=e[i].next,v=e[i].v)
				if((u==s||h[u]==h[v]+1)&&push(u,v,i)&&v!=t&&v!=s)
					Q.push(v);
			if(u!=s&&prs[u])
			{
				if(!(--cnt[h[u]])) Gap(h[u]);
				++cnt[++h[u]]; Q.push(u);
			}
		}
		return prs[t];
	}
}
int n,m,s,t,u,v,w;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&m,&s,&t);
	while(m-->0)
	{
		scanf("%d%d%d",&u,&v,&w);
		HLPP::AddEdge(u,v,w);
	}
	printf("%d\n",HLPP::Maxflow(n,s,t));
	return 0;
}
//#include<cstdio>
//#include<cstring>
//#include<vector>
//#include<queue>
//#include<algorithm> 
//using namespace std;
//const int oo=1e9+7;
//const int maxn=10005;
//struct Edge { int from,to,cap,flow; };
//struct Dinic
//{
//	int n,m,s,t;
//	vector<Edge> edges;
//	vector<int> G[maxn];
//	bool vis[maxn];
//	int d[maxn],pos[maxn];
//	inline void AddEdge(int from,int to,int cap)
//	{
//		edges.push_back((Edge){from,to,cap,0});
//		edges.push_back((Edge){to,from,0,0});
//		m=edges.size();
//		G[from].push_back(m-2);
//		G[to].push_back(m-1);
//	}
//	inline bool BFS()
//	{
//		memset(vis,0,sizeof(vis));
//		queue<int> Q;
//		Q.push(s); vis[s]=true; d[s]=0;
//		while(Q.size())
//		{
//			int u=Q.front(); Q.pop();
//			for(int i=0;i<G[u].size();i++)
//			{
//				Edge &e=edges[G[u][i]];
//				if(!vis[e.to]&&e.cap>e.flow)
//				{
//					vis[e.to]=true;
//					d[e.to]=d[u]+1;
//					Q.push(e.to);
//				}
//			}
//		}
//		return vis[t];
//	}
//	inline int DFS(int u,int a)
//	{
//		if(u==t||a==0) return a;
//		int flow=0,f;
//		for(int &i=pos[u];i<G[u].size();i++)
//		{
//			Edge &e=edges[G[u][i]];
//			if(d[u]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0)
//			{
//				e.flow+=f; flow+=f;
//				edges[G[u][i]^1].flow-=f; a-=f;
//				if(a==0) break;
//			}
//		}
//		return flow;
//	}
//	int Maxflow(int s,int t)
//	{
//		this->s=s; this->t=t;
//		int flow=0;
//		while(BFS())
//		{
//			memset(pos,0,sizeof(pos));
//			flow+=DFS(s,oo);
//		}
//		return flow;
//	}
//}dinic;
//int n,m,s,t,u,v,w;
//int main()
//{
//#ifdef local
//	freopen("pro.in","r",stdin);
//#endif
//	scanf("%d%d%d%d",&n,&m,&s,&t);
//	while(m-->0)
//	{
//		scanf("%d%d%d",&u,&v,&w);
//		dinic.AddEdge(u,v,w);
//	}
//	printf("%d\n",dinic.Maxflow(s,t));
//	return 0;
//}
