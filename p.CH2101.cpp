//http://contest-hunter.org:83/contest/0x20%E3%80%8C%E6%90%9C%E7%B4%A2%E3%80%8D%E4%BE%8B%E9%A2%98/2101%20%E5%8F%AF%E8%BE%BE%E6%80%A7%E7%BB%9F%E8%AE%A1
#include<cstdio>
#include<bitset>
#include<stack>
#include<vector>
using namespace std;
const int maxn=30005;
int n,m,d[maxn],rk[maxn],cnt;
vector<int> G[maxn];
bitset<maxn> f[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		G[y].push_back(x); d[x]++;
	}
	stack<int> stk;
	for(int i=1;i<=n;i++) if(d[i]==0) stk.push(i);
	while(stk.size())
	{
		int u=stk.top(); stk.pop(); rk[cnt++]=u;
		for(int v:G[u])
		{
			d[v]--;
			if(!d[v]) stk.push(v);
		}
	}
	for(int i=1;i<=n;i++) f[i][i-1]=1;
	for(int i=0;i<n;i++)
	{
		int u=rk[i];
		for(int v:G[u]) f[v]|=f[u];
	}
	for(int i=1;i<=n;i++) printf("%d\n",f[i].count());
	return 0;
}
