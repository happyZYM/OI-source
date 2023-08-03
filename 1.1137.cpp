#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<cassert>
using namespace std;
const int maxn=100005;
int n,m,f[maxn];
vector<int> G[maxn];
int in[maxn],tp[maxn],cnt;
stack<int> stk;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		G[x].push_back(y); in[y]++;
	}
	for(int i=1;i<=n;i++) if(in[i]==0) { tp[++cnt]=i; stk.push(i); }
	while(stk.size())
	{
		int u=stk.top(); stk.pop();
		for(int v:G[u])
		{
			in[v]--;
			if(!in[v]) { tp[++cnt]=v; stk.push(v); }
		}
	}
	for(int i=1;i<=n;i++) f[i]=1;
	assert(cnt==n);
	for(int i=1;i<=n;i++)
	{
		int u=tp[i];
		for(int v:G[u]) f[v]=max(f[v],f[u]+1);
	}
	for(int i=1;i<=n;i++) printf("%d\n",f[i]);
	return 0;
}
