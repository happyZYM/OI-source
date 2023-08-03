#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<cassert>
using namespace std;
#define mkp make_pair
const int maxn=1e5+5;
const int maxrc=1e6+5;
int n,r,c,x[maxn],y[maxn],T[maxn],dfn[maxn],lowlink[maxn],sccno[maxn],dfs_cnt,scc_cnt,f[maxn],p[maxn],p_cnt,in[maxn],tt[maxn];
vector<int> CR[maxrc],CC[maxrc],SR[maxrc],SC[maxrc],A[maxn],B[maxn];
map<pair<int,int>,int> hsh;
stack<int> S;
void dfs(int u)
{
    dfn[u]=lowlink[u]=++dfs_cnt;
    S.push(u);
	for(int v:A[u])
        if(!dfn[v])
        {
            dfs(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }
        else if(!sccno[v]) lowlink[u]=min(lowlink[u],dfn[v]);
    if(lowlink[u]==dfn[u])
    {
        scc_cnt++;
        while(true)
        {
            int x=S.top(); S.pop();
            sccno[x]=scc_cnt;
            if(x==u) break;
        }
    }
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&r,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&T[i]);
		hsh[mkp(x[i],y[i])]=i;
		if(T[i]==1)
		{
			CR[x[i]].push_back(i);
			SC[y[i]].push_back(i);
		}
		if(T[i]==2)
		{
			CC[y[i]].push_back(i);
			SR[x[i]].push_back(i);
		}
		if(T[i]==3)
		{
			SR[x[i]].push_back(i);
			SC[y[i]].push_back(i);
		}
	}
	for(int i=1;i<=r;i++)
	{
		int tot=CR[i].size();
		if(tot==0) continue;
		int u=CR[i][0];
		for(int v:SR[i]) A[u].push_back(v);
		if(tot==1) continue;
		for(int j=0;j<tot;j++) A[CR[i][j]].push_back(CR[i][(j+1)%tot]);
	}
	for(int i=1;i<=c;i++)
	{
		int tot=CC[i].size();
		if(tot==0) continue;
		int u=CC[i][0];
		for(int v:SC[i]) A[u].push_back(v);
		if(tot==1) continue;
		for(int j=0;j<tot;j++) A[CC[i][j]].push_back(CC[i][(j+1)%tot]);
	}
	int dr[]={-1,-1,-1,0,1,1,1,0},dc[]={-1,0,1,1,1,0,-1,-1};
	for(int i=1;i<=n;i++) for(int j=0;j<8;j++) if(T[i]==3)
	{
		int nr=x[i]+dr[j],nc=y[i]+dc[j];
		if(hsh.find(mkp(nr,nc))!=hsh.end()) A[i].push_back(hsh[mkp(nr,nc)]);
	}
	//printf("Edges:\n");
	for(int i=1;i<=n;i++)
	{
		sort(A[i].begin(),A[i].end());
		int len=unique(A[i].begin(),A[i].end())-A[i].begin();
		A[i].resize(len);
	//	for(int v:A[i]) printf("%d -> %d\n",i,v);
	}
	//printf("\n");
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
	for(int i=1;i<=n;i++) f[sccno[i]]++;
	for(int u=1;u<=n;u++) for(int v:A[u]) if(sccno[v]!=sccno[u]) B[sccno[u]].push_back(sccno[v]);
	for(int i=1;i<=scc_cnt;i++)
	{
		sort(B[i].begin(),B[i].end());
		int len=unique(B[i].begin(),B[i].end())-B[i].begin();
		B[i].resize(len);
		for(int v:B[i]) in[v]++;
		tt[i]=f[i];
	}
	stack<int> stk;
	for(int i=1;i<=scc_cnt;i++) if(!in[i]) stk.push(i);
	while(stk.size())
	{
		int u=stk.top(); stk.pop(); p[++p_cnt]=u;
		for(int v:B[u])
		{
			in[v]--;
			if(!in[v]) stk.push(v);
		}
	}
	int res=0;
	for(int i=1;i<=scc_cnt;i++)
	{
		int u=p[i];
		for(int v:B[u]) f[v]=max(f[v],f[u]+tt[v]);
		res=max(res,f[u]);
	}
	printf("%d\n",res);
	return 0;
}
