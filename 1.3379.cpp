#include<cstdio>
const int maxn=500005;
const int maxm=50000*2+5;
struct Rec { int to,lca; Rec *next; };
Rec edge[maxm],*E[maxn],*ecnt=edge;
Rec query[maxm],*Q[maxn],*qcnt=query;
inline void AddEdge(Rec **G,Rec* &ecnt,int from,int to)
{ ecnt->to=to; ecnt->next=G[from]; G[from]=ecnt++; }
int n,m,s;
bool vis[maxn];
int fa[maxn];
inline int ff(int x)
{
	int a=x,b;
	while(x!=fa[x]) x=fa[x];
	while(a!=x)
	{
		b=fa[a];
		fa[a]=x;
		a=b;
	}
	return x;
}
void dfs(int u)
{
	fa[u]=u;
	vis[u]=true;
	for(Rec *it=E[u];it;it=it->next)
		if(!vis[it->to])
		{
			dfs(it->to);
			fa[it->to]=u;
		}
	for(Rec *it=Q[u];it;it=it->next)
		if(vis[it->to])
		{
			it->lca=ff(it->to);
			(query+((it-query)^1))->lca=it->lca;
		}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n-1;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		AddEdge(E,ecnt,a,b); AddEdge(E,ecnt,b,a);
	}
	for(int i=0;i<m;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		AddEdge(Q,qcnt,a,b); AddEdge(Q,qcnt,b,a);
	}
	dfs(s);
	for(int i=0;i<m;i++) printf("%d\n",query[i*2].lca);
	return 0;
}
/*
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=500005;
struct Node { int v; Node *next; };
int n,m,s;
int dep[maxn],anc[maxn][30];
Node mem[maxn*2],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; }
void cal(int o,int fa)
{
	dep[o]=dep[anc[o][0]]+1;
	for(int i=1;i<=25;i++) anc[o][i]=anc[anc[o][i-1]][i-1];
	for(Node *it=G[o];it;it=it->next)
		if(it->v!=fa)
		{
			anc[it->v][0]=o;
			cal(it->v,o);
		}
}
inline int getLCA(int a,int b)
{
	if(a==b) return a;
	if(dep[b]>dep[a]) swap(a,b);
	for(int i=25;i>=0;i--)
		if(dep[anc[a][i]]>=dep[b]) a=anc[a][i];
	if(a==b) return a;
	for(int i=25;i>=0;i--)
		if(anc[a][i]!=anc[b][i]) a=anc[a][i],b=anc[b][i];
	return anc[a][0];
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		AddEdge(x,y); AddEdge(y,x);
	}
	cal(s,0);
	while(m-->0)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",getLCA(x,y));
	}
	return 0;
}
*/
