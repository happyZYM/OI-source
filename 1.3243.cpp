#include<cstdio>
#include<algorithm>
#include<cassert>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=100005;
int T,n,m;
vector<int> G[maxn];
int in[maxn],res[maxn],cnt;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) G[i].clear();
		memset(in,0,sizeof(in)); cnt=0;
		for(int i=0;i<m;i++)
		{
			int x,y; scanf("%d%d",&x,&y);
			G[y].push_back(x); in[x]++;
		}
		priority_queue<int> Q;
		for(int i=1;i<=n;i++) if(in[i]==0) Q.push(i);
		while(Q.size())
		{
			int u=Q.top(); Q.pop(); res[cnt++]=u;
			for(int v:G[u])
			{
				in[v]--;
				if(!in[v]) Q.push(v);
			}
		}
		for(int i=1;i<=n;i++) if(in[i]) { puts("Impossible!"); goto nxt; }
		while(cnt) printf("%d ",res[--cnt]); puts("");
		nxt:continue;
	}
	return 0;
}
