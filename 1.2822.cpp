#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2005;
int t,k,n,m;
int C[maxn][maxn],d[maxn][maxn],sum[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&t,&k);
	n=2000;
	for(int i=0;i<=n;i++) C[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%k;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			d[i][j]=(C[i][j]%k==0);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			sum[i][j]=d[i][j]+(i>0?sum[i-1][j]:0)+(j>0?sum[i][j-1]:0)-(i>0&&j>0?sum[i-1][j-1]:0);
	while(t-->0)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",sum[n][m]);
	}
	return 0;
}
