#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
int n,a[maxn],s[maxn];
int f[maxn][maxn],g[maxn][maxn],d[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		s[0]=0;
		for(int i=1;i<=n;i++) { scanf("%d",&a[i]); s[i]=s[i-1]+a[i]; }
		for(int i=1;i<=n;i++) f[i][i]=g[i][i]=d[i][i]=a[i];
		for(int L=1;L<n;L++)
			for(int i=1;i+L<=n;i++)
			{
				int j=i+L;
				int m=0;
				m=min(m,f[i+1][j]);
				m=min(m,g[i][j-1]);
				d[i][j]=s[j]-s[i-1]-m;
				f[i][j]=min(d[i][j],f[i+1][j]);
				g[i][j]=min(d[i][j],g[i][j-1]);
			}
		printf("%d\n",2*d[1][n]-s[n]);
	}
	return 0;
}
/*
d[1][1]=4
d[2][2]=-10
d[3][3]=-20
d[4][4]=7
d[1][4]=-6

*/
