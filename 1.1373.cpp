#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=805;
const int mod=1e9+7;
int n,m,p,a[maxn][maxn],f[maxn][maxn][20][2];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d%d",&n,&m,&p); p++;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) f[i][j][a[i][j]%p][0]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=0;k<p;k++)
	{
		int v=f[i][j][k][0];
		(f[i+1][j][((k-a[i+1][j])%p+p)%p][1]+=v)%=mod;
		(f[i][j+1][((k-a[i][j+1])%p+p)%p][1]+=v)%=mod;
		v=f[i][j][k][1];
		(f[i+1][j][(k+a[i+1][j])%p][0]+=v)%=mod;
		(f[i][j+1][(k+a[i][j+1])%p][0]+=v)%=mod;
	}
	int res=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) (res+=f[i][j][0][1])%=mod;
	printf("%d\n",res);
	return 0;
}