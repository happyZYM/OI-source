#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=2010;
const int oo=1<<29;
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
inline void read(T& t,Args&... args)
{
    read(t); read(args...);
}
struct Edge
{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f) { }
};
struct Dinic
{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];
	inline void AddEdge(int from,int to,int cap)
	{
		edges.push_back((Edge){from,to,cap,0});
		edges.push_back((Edge){to,from,0,0});
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	inline bool BFS()
	{
		memset(vis,0,sizeof(vis));
		queue<int> Q;
		Q.push(s); d[s]=0; vis[s]=true;
		while(Q.size())
		{
			int u=Q.front(); Q.pop();
			for(int i=0;i<G[u].size();i++)
			{
				Edge &e=edges[G[u][i]];
				if(!vis[e.to]&&e.cap>e.flow)
				{
					vis[e.to]=true;
					d[e.to]=d[u]+1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	int DFS(int u,int a)
	{
		if(u==t||a==0) return a;
		int flow=0,f;
		for(int &i=cur[u];i<G[u].size();i++)
		{
			Edge &e=edges[G[u][i]];
			if(d[u]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0)
			{
				e.flow+=f; flow+=f;
				edges[G[u][i]^1].flow-=f; a-=f;
				if(a==0) break;
			}
		}
		return flow;
	}
	int Maxflow(int s,int t)
	{
		this->s=s; this->t=t;
		int flow=0;
		while(BFS())
		{
			memset(cur,0,sizeof(cur));
			flow+=DFS(s,oo);
		}
		return flow;
	}
}MainAgo;
int n,m,e,u,v,s,t;
int color[maxn];
void dfs(int o,int c)
{
	if(color[o]) return;
	color[o]=c;
	int sz=MainAgo.G[o].size();
	for(int i=0;i<sz;i++) dfs(MainAgo.edges[i].to,3-c);
}
int main()
{
	read(n,m,e);
	for(int i=0;i<e;i++)
	{
		read(u,v);
		if(v>m) continue;
		MainAgo.AddEdge(u,n+v,1);
	}
	s=n+m+1; t=n+m+2;
	for(int i=1;i<=n;i++) MainAgo.AddEdge(s,i,1);
	for(int i=1;i<=m;i++) MainAgo.AddEdge(i+n,t,1);
	printf("%d\n",MainAgo.Maxflow(s,t));
	return 0;
}
