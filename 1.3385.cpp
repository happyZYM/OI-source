#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=2005;
const int maxm=6005;
struct Edge { int v,w; Edge *next; };
Edge *G[maxn],mem[maxm],*ecnt;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->next=G[u]; G[u]=ecnt++; }
int T,n,m;
int dis[maxn],len[maxn];
bool inq[maxn],searched[maxn];
bool spfa(int s)
{
	queue<int> que;
	memset(inq,false,sizeof(inq));
	memset(dis,0x3F,sizeof(dis));
	que.push(s);
	dis[s]=0; inq[s]=true; len[s]=0; searched[s]=true;
	while(que.size())
	{
		int u=que.front(); que.pop(); inq[u]=false;
		for(Edge *it=G[u];it;it=it->next)
			if(dis[it->v]>dis[u]+it->w)
			{
				dis[it->v]=dis[u]+it->w;
				len[it->v]=len[u]+1;
				searched[it->v]=true;
				if(len[it->v]>=n) return true;
				if(!inq[it->v]) { inq[it->v]=true; que.push(it->v); }
			}
	}
	return false;
}
bool check()
{
	memset(searched,0,sizeof(searched));
	for(int i=1;i<=n;i++) if(!searched[i]&&spfa(i)) return true;
	return false;
}
int main()
{
	scanf("%d",&T);
	while(T-->0)
	{
		memset(G,0,sizeof(G)); ecnt=mem;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			int a,b,w; scanf("%d%d%d",&a,&b,&w);
			AddEdge(a,b,w);
			if(w>=0) AddEdge(b,a,w);
		}
		puts(check()?"YE5":"N0");
	}
	return 0;
}
