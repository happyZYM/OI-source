#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
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
const int maxn=65;
const int maxm=32005;
int f[maxn][maxm];
vector<int> son[maxn];
int V[maxn],W[maxn];
int n,m,v,p,q;
int sz[maxn],suf[maxn],cnt;
void dfs(int u)
{
	sz[u]=1;
	for(int i=0;i<son[u].size();i++) { dfs(son[u][i]); sz[u]+=sz[son[u][i]]; }
	suf[++cnt]=u;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(m,n);
	for(int i=1;i<=n;i++)
	{
		read(v,p,q);
		V[i]=v*p; W[i]=v; son[q].push_back(i);
	}
	dfs(0);
	for(int i=1;i<=cnt;i++)
	{
		int now=suf[i];
		for(int j=m;j>=0;j--)
			if(j>=W[now]) f[i][j]=max(f[i-sz[now]][j],f[i-1][j-W[now]]+V[now]);
			else f[i][j]=f[i-sz[now]][j];
	}
	printf("%d\n",f[cnt][m]);
	return 0;
}
