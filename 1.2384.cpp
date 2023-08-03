#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int mod=9987;
const int maxn=1005;
const int maxm=1000005;
struct Edge
{
	int to,w;
	Edge *next;
};
queue<int> q;
int n,m,x,y,z;
int pre[maxn][2],vis[maxn],tot=0;
double dis[maxn];
Edge *e[maxn],mem[maxm],*ecnt=mem;
void AddEdge(int u,int v,int val)
{
	ecnt->to=v; ecnt->w=val; ecnt->next=e[u];
	e[u]=ecnt++;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    while(m-->0)
    {
        scanf("%d%d%d",&x,&y,&z);
        AddEdge(x,y,z);
    }
    memset(dis,127,sizeof(dis));
    dis[1]=0; vis[1]=1; q.push(1);
    while(q.size())
    {
        int u=q.front();q.pop();
        vis[u]=0;
        for(Edge *it=e[u];it;it=it->next)
        {
            int v=it->to;
            if(dis[v]>dis[u]+log(it->w))
            {
                dis[v]=dis[u]+log(it->w);
                pre[v][0]=u;pre[v][1]=it->w;
                if(!vis[v]) {vis[v]=1;q.push(v);}
            }
        }
    }
    int res=1,pos=n;
    while(pos!=1)
    {
        res*=pre[pos][1];
        res%=mod;
        pos=pre[pos][0];
    }
    printf("%d\n",res);
    return 0;
}
