#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<sstream>
#include<vector>
using namespace std;
const int maxn=205;
const int oo=0x3f3f3f3f;
map<string,int> mp;
int n,m,id,w[maxn],fa[maxn],sum[maxn],f[maxn][maxn];
inline int ID(const string &s)
{
	if(mp.find(s)==mp.end()) mp[s]=++id;
	return mp[s];
}
vector<int> G[maxn];
void dfs(int u)
{
	sum[u]=1;
	for(int i=0;i<G[u].size();i++) { dfs(G[u][i]); sum[u]+=sum[G[u][i]]; }
	f[u][0]=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		for(int j=sum[u];j>=0;j--)
			for(int k=0;k<=sum[v]&&k<=j;k++)
				f[u][j]=min(f[u][j],f[u][j-k]+f[v][k]);
	}
	f[u][sum[u]]=min(f[u][sum[u]],w[u]);
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	w[0]=oo;
	while(cin>>n>>m)
	{
		id=0; mp.clear(); memset(fa,0,sizeof(fa)); memset(f,0x3f,sizeof(f)); memset(sum,0,sizeof(sum));
		for(int i=0;i<=n;i++) G[i].clear();
		string tmp; getline(cin,tmp);
		for(int i=1;i<=n;i++)
		{
			string s; getline(cin,s);
			stringstream ss(s);
			ss>>s;
			int u=ID(s);
			ss>>w[u];
			while(ss>>s) fa[ID(s)]=u;
		}
		for(int i=1;i<=n;i++) G[fa[i]].push_back(i);
		dfs(0);
		int res=oo;
		for(int i=m;i<=n;i++) res=min(res,f[0][i]);
		printf("%d\n",res);
	}
	return 0;
}