#include<cstdio>
#include<stack>
#include<vector>
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
inline void write(int v)
{
	int stk[10],top;
	while(v>0) stk[top++]=v%10,v/=10;
	while(top>0) putchar(stk[--top]+'0');
	putchar(' ');
}
const int maxn=1e6+5;
struct Edge { int u,v; };
int pre[maxn],bccno[maxn],dfs_clock,bcc_cnt; bool iscut[maxn];
vector<int> G[maxn],bcc[maxn];
stack<Edge> stk;
int dfs(int u,int fa)
{
	int lowu=pre[u]=++dfs_clock,child=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		Edge e=(Edge){u,v};
		if(!pre[v])
		{
			stk.push(e);
			child++;
			int lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>=pre[u])
			{
				iscut[u]=true; bcc_cnt++;
				while(true)
				{
					Edge x=stk.top(); stk.pop();
					if(bccno[x.u]!=bcc_cnt) { bcc[bcc_cnt].push_back(x.u); bccno[x.u]=bcc_cnt; }
					if(bccno[x.v]!=bcc_cnt) { bcc[bcc_cnt].push_back(x.v); bccno[x.v]=bcc_cnt; }
					if(x.u==u&&x.v==v) break;
				}
			}
		}
		else if(pre[v]<pre[u]&&v!=fa)
		{
			stk.push(e);
			lowu=min(lowu,pre[v]);
		}
	}
	if(fa<0&&child<=1) iscut[u]=false;
	return lowu;
}
int n,m,a,b; 
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
	freopen("pro.out","w",stdout);
#endif
	read(n,m);
	while(m-->0)
	{
		read(a,b);
		G[a].push_back(b); G[b].push_back(a);
	}
	for(int i=1;i<=n;i++) if(!pre[i]) dfs(i,-1);
	printf("%d\n",bcc_cnt);
	for(int i=1;i<=bcc_cnt;i++)
	{
		printf("%d ",bcc[i].size());
		for(int j=0;j<bcc[i].size();j++) write(bcc[i][j]);
		putchar('\n');
	}
	return 0;
}
