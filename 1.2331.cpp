#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
const int oo=0x3f3f3f3f;
int n,m,k,a[maxn][3],f[15][maxn][5];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	if(m==1)
	{
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
			{
				f[i][j][0]=max(f[i][j-1][0],f[i][j-1][1]);
				f[i][j][1]=max(f[i-1][j-1][0],f[i][j-1][1])+a[j][1];
			}
		printf("%d\n",max(f[k][n][0],f[k][n][1]));
	}
	else
	{
		for(int i=0;i<=k;i++) for(int j=0;j<=n;j++) for(int l=0;l<5;l++) f[i][j][l]=-oo;
		for(int i=0;i<=k;i++) for(int j=0;j<=n;j++) f[i][j][0]=0;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
			{
				int x=a[j][1],y=a[j][2];

				f[i][j][0]=max(max(f[i][j-1][0],f[i][j-1][1]),max(f[i][j-1][2],f[i][j-1][3]));
				f[i][j][0]=max(f[i][j][0],f[i][j-1][4]);

				f[i][j][1]=max(max(f[i-1][j-1][0],f[i][j-1][1]),max(f[i-1][j-1][2],f[i][j-1][3]))+x;
				f[i][j][1]=max(f[i][j][1],f[i-1][j-1][4]+x);

				f[i][j][2]=max(max(f[i-1][j-1][0],f[i-1][j-1][1]),max(f[i][j-1][2],f[i][j-1][3]))+y;
				f[i][j][2]=max(f[i][j][2],f[i-1][j-1][4]+y);

				f[i][j][3]=max(max(f[i-1][j-1][1],f[i-1][j-1][2]),f[i][j-1][3])+x+y;
				if(i>=2) f[i][j][3]=max(f[i][j][3],f[i-2][j-1][4]+x+y);

				f[i][j][4]=max(max(f[i-1][j-1][0],f[i-1][j-1][1]),max(f[i-1][j-1][2],f[i-1][j-1][3]))+x+y;
				f[i][j][4]=max(f[i][j][4],f[i][j-1][4]+x+y);
			}
		printf("%d\n",max(max(max(f[k][n][0],f[k][n][1]),max(f[k][n][2],f[k][n][3])),f[k][n][4]));
	}
	return 0;
}
