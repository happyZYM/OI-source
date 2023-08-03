#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=100000;
struct node
{
	int v,c;
	node *next;
}edge[MAXN*4+10];
node *adj[MAXN+10];
node *ecnt=edge;
inline void addedge(int u,int v,int c)
{
	node *p=++ecnt;
	p->v=v;
	p->c=c;
	p->next=adj[u];
	adj[u]=p;
}
int d[MAXN+10],path[MAXN+10];
bool vis[MAXN+10];
queue<int> q;
int n,m;
void bfs1(int s)
{
	memset(d,0,sizeof(d));
	d[s]=1;
	q.push(s);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for(node *p=adj[u];p;p=p->next)
		{
			int v=p->v;
			if(!d[v])
			{
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}
queue<pair<int,int>> q2;
void bfs2(int s)
{
	memset(path,0x3f,sizeof(path));
	memset(vis,0,sizeof(vis));
	q2.push(make_pair(s,0));
	path[0]=0;
	while(!q2.empty())
	{
		int u=q2.front().first;
		int cy=q2.front().second;
		q2.pop();
		if(path[d[1]-d[u]]!=cy||vis[u]) continue;
		vis[u]=true;
		for (node *p=adj[u];p;p=p->next)
		{
			int v=p->v;
			int c=p->c;
			if (d[u] != d[v] + 1 || path[d[1] - d[v]] <= c) continue;
			path[d[1]-d[v]]=c;
		}
		for(node *p=adj[u];p;p=p->next)
		{
			int v=p->v;
			int c=p->c;
			if(d[u]!=d[v]+1||path[d[1]-d[v]]!=c) continue;
			q2.push(make_pair(v,c));
		}
	}
	d[1]--;
	int i;
	printf("%d\n",d[1]);
	for(i=1;i<=d[1];i++)
		printf("%d%c",path[i],i==d[1]?'\n':' ');
}

int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int u,v,w,i;
	while(scanf("%d%d",&n,&m)==2)
	{
		memset(adj,0,sizeof(adj));
		ecnt=edge;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		bfs1(n);
		bfs2(1);
	}
	return 0;
}
