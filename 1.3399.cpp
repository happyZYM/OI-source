#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,m,d[maxn],c[maxn],f[maxn][maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1;i<=m;i++) scanf("%d",&c[i]);
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<i;j++) f[i][j]=f[i][j-1];
		for(int j=i;j<=m;j++) f[i][j]=min(f[i][j-1],f[i-1][j-1]+d[i]*c[j]);
	}
	printf("%d\n",f[n][m]);
	return 0;
}