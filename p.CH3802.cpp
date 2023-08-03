//http://contest-hunter.org:83/contest/0x30%E3%80%8C%E6%95%B0%E5%AD%A6%E7%9F%A5%E8%AF%86%E3%80%8D%E4%BE%8B%E9%A2%98/3802%20%E7%BB%BF%E8%B1%86%E8%9B%99%E7%9A%84%E5%BD%92%E5%AE%BF
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=100005;
struct Edge { int v,w; Edge *nxt; };
Edge mem[maxn*2],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->nxt=G[u]; G[u]=ecnt++; }
int deg[maxn],in[maxn];
int n,m;
double f[maxn];
queue<int> Q;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;  scanf("%d%d%d",&x,&y,&z);
		AddEdge(y,x,z);
		in[x]++; deg[x]++;
	}
	Q.push(n);
	while(Q.size())
	{
		int u=Q.front(); Q.pop();
		for(Edge *it=G[u];it;it=it->nxt)
		{
			f[it->v]+=(f[u]+it->w)/deg[it->v];
			in[it->v]--;
			if(in[it->v]==0) Q.push(it->v);
		}
	}
	printf("%.2lf\n",f[1]);
}
