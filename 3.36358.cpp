#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;++i)
template<typename T> inline void read(T& t)
{
    t=0; int ch,f=false;
    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
    if(ch=='-') f=true,ch=getchar();
    t=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+(ch^48);
    if(f) t=-t;
}
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
const int maxn=1005;
const int maxm=1000005;
const int oo=0x3f3f3f3f;
struct Edge { int v,w; Edge *next; };
Edge mem[maxm],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v,int w) { ecnt->v=v; ecnt->w=w; ecnt->next=G[u]; G[u]=ecnt++; }
int du[maxn],stk1[maxn],top1,stk2[maxn],top2;
int ve[maxn],vl[maxn];
int main()
{
	int n,m,u,v,w,res=0;
	read(n,m);
	while(m-->0)
	{
		read(u,v,w);
		AddEdge(u,v,w);
		++du[v];
	}
	For(i,1,n) if(!du[i]) stk1[top1++]=stk2[top2++]=i;
	while(top1>0)
	{
		int u=stk1[--top1];
		for(Edge *it=G[u];it;it=it->next)
		{
			ve[it->v]=max(ve[it->v],ve[u]+it->w);
			if(--du[it->v]==0) stk2[top2++]=stk1[top1++]=it->v;
		}
	}
	memset(vl,oo,sizeof(vl));
	vl[stk2[n-1]]=ve[stk2[n-1]];
	while(top2>0)
	{
		int u=stk2[--top2];
		for(Edge *it=G[u];it;it=it->next) vl[u]=min(vl[u],vl[it->v]-it->w);
	}
	For(i,1,n) for(Edge *it=G[i];it;it=it->next)
		if(ve[i]==vl[it->v]-it->w) res+=it->w;
	printf("%d\n",res);
	return 0;
}
