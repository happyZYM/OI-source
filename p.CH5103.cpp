#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[60][60],f[100][60][60];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	f[0][1][1]=a[1][1];
	for(int i=0;i<n+m-2;i++)
		for(int x1=1;x1<=min(n,i+1);x1++)
			for(int x2=1;x2<=min(n,i+10);x2++)
			{
				int y1=i+2-x1,y2=i+2-x2;
				f[i+1][x1][x2]		=max(f[i+1][x1][x2],
										 f[i][x1][x2] + a[x1][y1+1]+((x1!=x2||y1+1!=y2+1)?a[x2][y2+1]:0));
				f[i+1][x1+1][x2]	=max(f[i+1][x1+1][x2],
										 f[i][x1][x2] + a[x1+1][y1]+((x1+1!=x2||y1!=y2+1)?a[x2][y2+1]:0));
				f[i+1][x1][x2+1]	=max(f[i+1][x1][x2+1],
										 f[i][x1][x2] + a[x1][y1+1]+((x1!=x2+1||y1+1!=y2)?a[x2+1][y2]:0));
				f[i+1][x1+1][x2+1]	=max(f[i+1][x1+1][x2+1],
										 f[i][x1][x2] + a[x1+1][y1]+((x1+1!=x2+1||y1!=y2)?a[x2+1][y2]:0));
			}
	printf("%d\n",f[n+m-2][n][n]);
	return 0;
}