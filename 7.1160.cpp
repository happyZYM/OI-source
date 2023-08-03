#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=305;
int n,m,a[maxn],f[35][maxn],d[maxn][maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	memset(f,0x3f,sizeof(f)); f[0][0]=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			int p=(i+j)/2;
			for(int k=i;k<=j;k++) d[i][j]+=abs(a[p]-a[k]);
		}
	for(int i=1;i<=m;i++)
		for(int j=i;j<=n;j++)
			for(int k=i-1;k<j;k++)
				f[i][j]=min(f[i][j],f[i-1][k]+d[k+1][j]);
	printf("%d\n",f[m][n]);
	return 0;
}