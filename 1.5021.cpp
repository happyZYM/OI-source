#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=50005;
int n,m,cnt;
vector<int> G[maxn],W[maxn];
multiset<int> s[maxn];
int dep[maxn];
void DFS(int u,int d)
{
	dep[u]=d;
	for(int i=0;i<G[u].size();i++)
	{
		int &v=G[u][i];
		if(!dep[v]) DFS(v,d+W[u][i]);
	}
}
int dfs(int u,int fa,int lim)
{
	s[u].clear();
	int val=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		val=dfs(v,u,lim)+W[u][i];
		if(val>=lim) cnt++;
		else s[u].insert(val);
	}
	int maxd=0;
	while(!s[u].empty())
	{
		multiset<int>::iterator bg=s[u].begin();
		if(s[u].size()==1) return max(maxd,*bg);
		multiset<int>::iterator it=s[u].lower_bound(lim-*bg);
		if(it==bg&&s[u].count(*it)==1) ++it;
		if(it==s[u].end())
		{
			maxd=max(maxd,*bg);
			s[u].erase(bg);
		}
		else
		{
			cnt++;
			s[u].erase(it);
			s[u].erase(s[u].begin());
		}
	}
	return maxd;
}
inline bool check(int lim)
{
	cnt=0;
	dfs(1,0,lim);
	return cnt>=m;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	int L=1,R,M,res=1;
	for(int i=1;i<=n-1;i++)
	{
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		G[u].push_back(v); G[v].push_back(u);
		W[u].push_back(w); W[v].push_back(w);
	}
	DFS(1,1);
	int rt=1;
	for(int i=2;i<=n;i++) if(dep[i]>dep[rt]) rt=i;
	memset(dep,0,sizeof(dep)); DFS(rt,1);
	R=dep[1];
	for(int i=2;i<=n;i++) R=max(R,dep[i]); R--;
	while(L<=R)
	{
		M=(L+R)>>1;
		if(check(M)) res=M,L=M+1;
		else R=M-1;
	}
	printf("%d\n",res);
	return 0;
}
