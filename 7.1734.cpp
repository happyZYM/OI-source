#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int maxn=305;
const int oo=0x3f3f3f3f;
int a[maxn][maxn],d[maxn][maxn],p[maxn][maxn];
int n,m,res;
vector<int> sol;
void dfs(int L,int R)
{
	if(p[L][R]==0) return;
	dfs(L,p[L][R]);
	sol.push_back(p[L][R]);
	dfs(p[L][R],R);
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++) a[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		a[y][x]=a[x][y]=min(a[x][y],z);
	}
	memcpy(d,a,sizeof(a));
	res=oo;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
			for(int j=i+1;j<k;j++)
				if((LL)d[i][j]+a[j][k]+a[k][i]<res)
				{
					res=d[i][j]+a[j][k]+a[k][i];
					sol.clear();
					sol.push_back(i);
					dfs(i,j);
					sol.push_back(j);
					sol.push_back(k);
				}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(d[i][k]+d[k][j]<d[i][j])
		{
			d[i][j]=d[i][k]+d[k][j];
			p[i][j]=k;
		}
	}
	if(res==oo) { puts("No solution."); return 0; }
	for(int i=0;i<sol.size();i++) printf("%d ",sol[i]); puts("");
	return 0;
}