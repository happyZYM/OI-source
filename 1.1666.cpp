#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned long long LL;
const int maxn=55;
int n,in[maxn];
string s[maxn];
LL f[maxn];
vector<int> G[maxn];
void dfs(int u)
{
	f[u]=1;
	for(int i=0;i<G[u].size();i++) { dfs(G[u][i]); f[u]*=f[G[u][i]]; }
	f[u]++;
}
inline bool cmp(const string &a,const string &b) { return a.size()<b.size(); }
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+n+1,cmp);
	// for(int i=1;i<=n;i++) cout<<s[i]<<endl;
	for(int i=n;i>=1;i--)
	{
		for(int j=i-1;j>=1;j--)
			if(s[i].substr(0,s[j].size())==s[j])
			{
				G[j].push_back(i);
				in[i]++;
				// printf("add %d %d\n",j,i);
				break;
			}
	}
	for(int i=1;i<=n;i++) if(in[i]==0) G[0].push_back(i);
	dfs(0);
	cout<<f[0]-1<<endl;
	return 0;
}