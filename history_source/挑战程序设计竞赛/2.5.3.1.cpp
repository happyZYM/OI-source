#include<cstdio>
#include<vector>
using namespace std;
int n,s;
vector<int> G[1001];
int color[1001];
void init()
{
	int a,b;
	scanf("%d%d",&n,&s);
	for(int i=0;i<s;i++)
	{
		scanf("%d%d",&a,&b);
		G[a].push_back(b);G[b].push_back(a);
	}
}
bool dfs(int v,int c)
{
	color[v]=c;
	for(int i=0;i<G[v].size();i++)
	{
		if(color[G[v][i]]==c) return 0;
		if(color[G[v][i]]==0&&!dfs(G[v][i],-c)) return 0;
	}
	return 1;
}
void solve()
{
	for(int i=0;i<n;i++)
		if(color[i]==0)
			if(!dfs(i,1))
			{
				printf("No\n");
				return;
			}
	printf("Yes\n");
}
int main()
{
	init();
	solve();
	return 0;
}
