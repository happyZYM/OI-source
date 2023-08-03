#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int oo=0x3f3f3f3f;
const int maxn=5005;
struct Edge { int from,to,cap,flow,cost; };
struct MCMF
{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool inq[maxn];
	int d[maxn],p[maxn],a[maxn];
	inline void AddEdge(int from,int to,int cap,int cost)
	{
		edges.push_back((Edge){from,to,cap,0,cost});
		edges.push_back((Edge){to,from,0,0,-cost});
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	inline bool BellmanFord(int &flow,int &cost)
	{
		memset(d,0x3f,sizeof(d));
		memset(inq,0,sizeof(inq));
		d[s]=0; inq[s]=true; p[s]=0; a[s]=oo;
		queue<int> Q;
		Q.push(s);
		while(Q.size())
		{
			int u=Q.front(); Q.pop(); inq[u]=false;
			for(int i=0;i<G[u].size();i++)
			{
				Edge &e=edges[G[u][i]];
				if(e.cap>e.flow&&d[e.to]>d[u]+e.cost)
				{
					d[e.to]=d[u]+e.cost;
					p[e.to]=G[u][i];
					a[e.to]=min(a[u],e.cap-e.flow);
					if(!inq[e.to]) { Q.push(e.to); inq[e.to]=true; }
				}
			}
		}
		if(d[t]==oo) return false;
		flow+=a[t];
		cost+=d[t]*a[t];
		int u=t;
		while(u!=s)
		{
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return true;
	}
	void Mincost(int s,int t,int &flow,int &cost)
	{
		flow=cost=0;
		this->s=s; this->t=t;
		while(BellmanFord(flow,cost));
	}
}mcmf;
int n,m,s,t,u,v,w,f;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&m,&s,&t);
	while(m-->0)
	{
		scanf("%d%d%d%d",&u,&v,&w,&f);
		mcmf.AddEdge(u,v,w,f);
	}
	int flow,cost;
	mcmf.Mincost(s,t,flow,cost);
	printf("%d %d\n",flow,cost);
	return 0;
}
