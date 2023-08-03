#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cstdlib>
#include<stack>
using namespace std;
const int maxn=5e4+5;
const int maxm=1e5+5;
int n,d,m,p[10],x[maxm],y[maxm];
char S[maxn],a[maxm],b[maxm];
vector<int> G[maxn*2];
int id[maxn][70];
int dfn[maxn*2],lowlink[maxn*2],sccno[maxn*2],dfs_cnt,scc_cnt;
stack<int> stk;
void dfs(int u)
{
	dfn[u]=lowlink[u]=++dfs_cnt;
	stk.push(u);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(!dfn[v])
		{
			dfs(v);
			lowlink[u]=min(lowlink[u],lowlink[v]);
		}
		else if(!sccno[v]) lowlink[u]=min(lowlink[u],dfn[v]);
	}
	if(lowlink[u]==dfn[u])
	{
		scc_cnt++;
		while(true)
		{
			int x=stk.top(); stk.pop();
			sccno[x]=scc_cnt;
			if(x==u) break;
		}
	}
}
void solve(int st)
{
	for(int i=0;i<n*2;i++) G[i].clear();
	memset(id,-1,sizeof(id));
	memset(dfn,0,sizeof(dfn));
	memset(lowlink,0,sizeof(lowlink));
	memset(sccno,0,sizeof(sccno));
	dfs_cnt=scc_cnt=0;
	for(int i=0;i<d;i++)
	{
		id[p[i]]['C']=1; id[p[i]][1]='C';
		id[p[i]][(st&&(1<<i))?'B':'A']=0; id[p[i]][0]=(st&&(1<<i))?'B':'A';
	}
	for(int i=0;i<n;i++)
	{
		if(S[i]=='A') { id[i]['B']=0; id[i]['C']=1; id[i][0]='B'; id[i][1]='C'; }
		if(S[i]=='B') { id[i]['A']=0; id[i]['C']=1; id[i][0]='A'; id[i][1]='C'; }
		if(S[i]=='C') { id[i]['A']=0; id[i]['B']=1; id[i][0]='A'; id[i][1]='B'; }
	}
//	printf("st=%d\n",st);
//	for(int i=0;i<n;i++)
//	{
//		for(char c:{'A','B','C'}) if(id[i][c]>-1) printf("id[%d][%c]=%d\n",i,c,id[i][c]);
//		for(int c:{0,1}) if(id[i][c]>-1) printf("bid[%d][%d]=%c\n",i,c,id[i][c]);
//	}
	for(int i=0;i<m;i++)
	{
		if(id[x[i]][a[i]]==-1) continue;
		int u=x[i]*2+id[x[i]][a[i]],v=y[i]*2+id[y[i]][b[i]];
		if(id[y[i]][b[i]]==-1) G[u].push_back(u^1);
		else
		{
			G[u].push_back(v);
			G[v^1].push_back(u^1);
		}
	}
	for(int i=0;i<2*n;i++) if(!dfn[i]) dfs(i);
	for(int i=0;i<2*n;i+=2) if(sccno[i]==sccno[i^1]) return;
	for(int i=0;i<n;i++) putchar(id[i][sccno[i*2]>sccno[i*2+1]]);
#ifdef local
//	puts("");
#endif
	exit(0);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%s%d",&n,&d,S,&m);
	for(int i=0;i<m;i++) { scanf("%d %c %d %c",&x[i],&a[i],&y[i],&b[i]); x[i]--; y[i]--; }
	d=0;
	for(int i=0;i<n;i++) if((S[i]-=32)&&(S[i]=='X')) p[d++]=i;
	for(int st=0;st<(1<<d);st++) solve(st);
	printf("-1");
#ifdef local
//	puts("");
#endif
	return 0;
}
