#include<cstdio>
#include<vector>
#include<stack>
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
const int maxn=1e6+7;
int n,m,x,xval,y,yval;
vector<int> G[maxn*2];
int id[maxn][70];
int dfn[maxn*2],lowlink[maxn*2],sccno[maxn*2],dfs_cnt,scc_cnt;
stack<int> stk;
void dfs(int u)
{
	dfn[u]=lowlink[u]=++dfs_cnt;
	stk.push(u);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(!dfn[v])
		{
			dfs(v);
			lowlink[u]=min(lowlink[u],lowlink[v]);
		}
		else if(!sccno[v]) lowlink[u]=min(lowlink[u],dfn[v]);
	}
	if(lowlink[u]==dfn[u])
	{
		scc_cnt++;
		while(true)
		{
			int x=stk.top(); stk.pop();
			sccno[x]=scc_cnt;
			if(x==u) break;
		}
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n,m);
	while(m-->0)
	{
		read(x,xval,y,yval);
		x--; y--;
		x=x*2+xval; y=y*2+yval;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}
	for(int i=0;i<2*n;i++) if(!dfn[i]) dfs(i);
	for(int i=0;i<2*n;i+=2) if(sccno[i]==sccno[i+1]) { puts("IMPOSSIBLE"); return 0; }
	puts("POSSIBLE");
	for(int i=0;i<n;i++) printf("%d ",sccno[i*2]>sccno[i*2+1]); puts("");
	return 0;
}
