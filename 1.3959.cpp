#include<cstdio>
#include<algorithm>
using namespace std; 
const int oo=2147483647;
int n,m,G[20][20],dp[10000],d[20],res=oo;
void dfs(int x)
{
	for(int i=1;i<=n;i++) if((1<<(i-1))&x)
		for(int j=1;j<=n;j++) if(((1<<(j-1))&x)==0&&G[i][j]!=oo)
			if(dp[x|(1<<(j-1))]>dp[x]+d[i]*G[i][j])
			{
				int tmp=d[j];
				d[j]=d[i]+1;
				dp[x|(1<<(j-1))]=dp[x]+d[i]*G[i][j];
				dfs(x|(1<<(j-1)));
				d[j]=tmp;
			}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) G[i][j]=oo;
	for(int i=1;i<=m;i++)
	{
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		G[v][u]=G[u][v]=min(G[u][v],w);
	}
	for(int u=1;u<=n;u++)
	{
		for(int i=1;i<=n;i++) d[i]=oo;
		for(int i=1;i<=(1<<n)-1;i++) dp[i]=oo;
		d[u]=1;
		dp[1<<(u-1)]=0;
		dfs(1<<(u-1));
		res=min(res,dp[(1<<n)-1]);
	} 
	printf("%d",res);
	return 0;
}
