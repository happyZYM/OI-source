#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100005;
int N,T,x;
vector<int> sons[maxn];
int dp(int u)
{
	if(sons[u].empty()) return 1;
	int k=sons[u].size();
	vector<int> d;
	for(int i=0;i<k;i++)
		d.push_back(dp(sons[u][i]));
	sort(d.begin(),d.end());
	int c=(k*T-1)/100+1;
	int ans=0;
	for(int i=0;i<c;i++) ans+=d[i];
	return ans;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&N,&T)==2&&N&&T)
	{
		for(int i=0;i<=N;i++) sons[i].clear();
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&x);
			sons[x].push_back(i);
		}
		printf("%d\n",dp(0));
	}
	return 0;
}
