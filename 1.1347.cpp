#include<cstdio>
#include<algorithm>
#include<cassert>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stack>
using namespace std;
int n,m;
struct Edge { int v,id; };
vector<Edge> G[30];
inline void AddEdge(int u,int v,int id) { G[u].push_back((Edge){v,id}); }
inline void solve(int id)
{
	static int in[30],res[30];
	memset(in,0,sizeof(in));
	for(int i=1;i<=n;i++) for(Edge it:G[i]) if(it.id<=id) in[it.v]++;
	stack<int> stk;
	for(int i=1;i<=n;i++) if(!in[i]) stk.push(i);
	bool unsure=0; int cnt=0;
	while(stk.size())
	{
		unsure|=(stk.size()>=2);
		int u=res[cnt++]=stk.top(); stk.pop();
		for(Edge it:G[u]) if(it.id<=id)
		{
			in[it.v]--;
			if(!in[it.v]) stk.push(it.v);
		}
	}
	for(int i=1;i<=n;i++) if(in[i])
	{
		printf("Inconsistency found after %d relations.\n",id);
		exit(0);
	}
	if(unsure) return;
	printf("Sorted sequence determined after %d relations: ",id);
	for(int i=0;i<cnt;i++) putchar(res[i]-1+'A');
	puts(".");
	exit(0);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	assert(m>=1);
	assert(m<=n*(n-1));
	for(int i=0;i<m;i++)
	{
		char s[10]; scanf("%s",s);
		int u=s[0]-'A'+1,v=s[2]-'A'+1;
		if(s[1]=='>') swap(u,v);
		AddEdge(u,v,i+1);
	}
	for(int i=1;i<=m;i++) solve(i);
	puts("Sorted sequence cannot be determined.");
	return 0;
}
