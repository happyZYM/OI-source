#include<cstdio>
#include<cstring>
#include<deque>
#include<algorithm>
using namespace std;
const int maxn=1005;
const int maxm=20005;
struct Edge { int v,w; Edge *nxt; };
Edge mem[maxm],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->nxt=G[u]; G[u]=ecnt++; }
int n,m,k,L,R,M,res;
int vis[maxn],d[maxn];
inline bool check(int M)
{
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	deque<int> Q;
	Q.push_back(1); d[1]=0;
	while(Q.size())
	{
		int u=Q.front(); Q.pop_front();
		vis[u]=1;
		for(Edge *it=G[u];it;it=it->nxt)
		{
			int w=(it->w>M);
			if(vis[it->v]||d[u]+w>=d[it->v]) continue;
			d[it->v]=d[u]+w;
			if(!w) Q.push_front(it->v);
			else Q.push_back(it->v);
		}
	}
	return d[n]<=k;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		AddEdge(u,v,w); AddEdge(v,u,w);
		R=max(R,w);
	}
	R++; int oo=res=R;
	while(L<=R)
	{
		M=(L+R)>>1;
		if(check(M)) res=M,R=M-1;
		else L=M+1;
	}
	if(res==oo) puts("-1");
	else printf("%d\n",res);
	return 0;
}
