#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int oo=0x3f3f3f3f;
const int maxn=1005;
int n;
int a[maxn],f[maxn],vis[maxn];
vector<int> G[maxn];
void dfs(int u,int c)
{
	if(vis[u]!=-1&&vis[u]!=c) { printf("0\n"); exit(0); }
	if(vis[u]!=-1) return;
	vis[u]=c;
	for(int i=0;i<G[u].size();i++) dfs(G[u][i],c^1);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[n+1]=oo;
	for(int i=n;i>=1;i--) f[i]=min(f[i+1],a[i]);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(f[j+1]<a[i]&&a[i]<a[j])
			{
				G[j].push_back(i);
				G[i].push_back(j);
			}
	memset(vis,-1,sizeof(vis));
	for(int i=1;i<=n;i++) if(vis[i]==-1) dfs(i,1);
	stack<int> s1,s2;
	int now=1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			printf("a ");
			s1.push(a[i]);
		}
		else
		{
			printf("c ");
			s2.push(a[i]);
		}
		while((s1.size()&&s1.top()==now)||(s2.size()&&s2.top()==now))
		{
			if(s1.size()&&s1.top()==now)
			{
				printf("b ");
				s1.pop();
			}
			else
			{
				printf("d ");
				s2.pop();
			}
			now++;
		}
	}
	return 0;
}
