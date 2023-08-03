#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=5005;
const int maxm=200005;
struct Edge { int v,w; Edge *next; };
Edge *G[maxn],mem[maxm*2],*ecnt=mem;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->next=G[u]; G[u]=ecnt++; }
int n,m,inq,res;
typedef pair<int,int> PII;
#define mkp make_pair
priority_queue<PII,vector<PII>,greater<PII> > Q;
int dis[maxn];
bool vis[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		AddEdge(a,b,c); AddEdge(b,a,c);
	}
	memset(dis,127,sizeof(dis));
	dis[1]=0;
	Q.push(mkp(0,1));
	while(!Q.empty()&&inq<n)
	{
		int u=Q.top().second,w=Q.top().first;
		Q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		res+=w;
		inq++;
		for(Edge *it=G[u];it;it=it->next)
			if(it->w<dis[it->v]) dis[it->v]=it->w,Q.push(mkp(dis[it->v],it->v));
	}
	if(inq==n) printf("%d\n",res);
	else printf("orz\n");
	return 0;
}
