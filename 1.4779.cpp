#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
template<typename T> inline void read(T& t)
{
    t=0; bool f=false; char ch;
    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
    if(ch=='-') f=true,ch=getchar();
    t=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+ch-'0';
    if(f) t=-t;
}
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
const int maxn=100005;
const int maxm=200005;
struct Edge { int v,w; Edge *next; };
struct Node { int u,dis; };
inline bool operator<(const Node &a,const Node &b) { return a.dis>b.dis; }
Edge mem[maxm],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->next=G[u]; G[u]=ecnt++; }
int n,m,s,u,v,w,d[maxn];
priority_queue<Node> Q; 
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n,m,s);
	while(m-->0)
	{
		read(u,v,w);
		AddEdge(u,v,w);
	}
	memset(d,0x3f,sizeof(d));
	d[s]=0; Q.push((Node){s,0});
	while(Q.size())
	{
		int u=Q.top().u,dis=Q.top().dis; Q.pop();
		if(dis>d[u]) continue;
		for(Edge *it=G[u];it;it=it->next)
		{
			int v=it->v;
			if(d[v]>d[u]+it->w)
			{
				d[v]=d[u]+it->w;
				Q.push((Node){v,d[v]});
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",d[i]);
	return 0;
}
