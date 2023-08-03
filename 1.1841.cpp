#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=205;
int n,m;
vector<int> G[maxn],V[maxn];
int mark[maxn],tot,vis[maxn],dis[maxn],way[maxn],pre[maxn];
struct Node { int u,d; };
inline bool operator<(const Node &a,const Node &b) { return a.d>b.d; }
void cal(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	memset(way,0,sizeof(way));
	dis[s]=0;
	priority_queue<Node> Q;
	Q.push((Node){s,0});
	while(Q.size())
	{
		int u=Q.top().u,d=Q.top().d; Q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i],w=V[u][i];
			if(d+w<dis[v]) { dis[v]=d+w; Q.push((Node){v,d+w}); }
		}
	}
	for(int u=1;u<=n;u++) for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i],w=V[u][i];
		if(dis[u]+w==dis[v]) { way[v]++; pre[v]=u; }
	}
	for(int i=1;i<=n;i++) if(way[i]==1&&pre[i]!=s) { mark[pre[i]]=true; tot=1; }
//	printf("s=%d\n",s);
//	for(int i=1;i<=n;i++) printf("dis[%d]=%d way[%d]=%d pre[%d]=%d\n",i,dis[i],i,way[i],i,pre[i]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	while(m-->0)
	{
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		G[a].push_back(b); V[a].push_back(c);
		G[b].push_back(a); V[b].push_back(c);
	}
	for(int i=1;i<=n;i++) cal(i);
	if(!tot) printf("No important cities.");
	else for(int i=1;i<=n;i++) if(mark[i]) printf("%d ",i);
	printf("\n");
	return 0;
}
