#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
const int maxn=1005;
const int maxm=10005;
int n,m,Q,dis[maxn],vis[maxn];
struct Edge { int v,w; Edge *nxt; };
Edge mem[maxm*2],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->nxt=G[u]; G[u]=ecnt++; }
int cal(int cost)
{
	memset(dis,0x3f,sizeof(dis)); memset(vis,0,sizeof(vis));
	dis[1]=0;
	deque<int> Q; Q.push_back(1);
	while(Q.size())
	{
		int u=Q.front(); Q.pop_front();
		if(vis[u]) continue;
		vis[u]=1;
		for(Edge *it=G[u];it;it=it->nxt)
		{
			int v=it->v,w=(it->w>cost?1:0);
			dis[v]=min(dis[v],dis[u]+w);
			if(w) Q.push_back(v);
			else Q.push_front(v);
		}
	}
	return dis[n];
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d%d",&n,&m,&Q);
	int L=0,R=0,M,res;
	for(int i=0;i<m;i++)
	{
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		AddEdge(u,v,w); AddEdge(v,u,w);
		R=max(R,w);
	}
	res=R+1; int oo=R+1;
	while(L<=R)
	{
		M=(L+R)>>1;
		if(cal(M)<=Q) res=M,R=M-1;
		else L=M+1;
	}
	printf("%d\n",res==oo?-1:res);
	return 0;
}