#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxL=205;
const int maxN=1005;
int L,N,c[maxL][maxL],f[maxN][maxL][maxL],p[maxN];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&L,&N);
	for(int i=1;i<=L;i++) for(int j=1;j<=L;j++) scanf("%d",&c[i][j]);
	p[0]=3;
	for(int i=1;i<=N;i++) scanf("%d",&p[i]);
	memset(f,0x3f,sizeof(f));
	f[0][1][2]=0;
	for(int i=0;i<=N;i++)
		for(int x=1;x<=L;x++)
		{
			if(x==p[i]) continue;
			for(int y=1;y<=L;y++)
			{
				if(y==p[i]) continue;
				f[i+1][x][y]=min(f[i+1][x][y],f[i][x][y]+c[p[i]][p[i+1]]);
				f[i+1][p[i]][y]=min(f[i+1][p[i]][y],f[i][x][y]+c[x][p[i+1]]);
				f[i+1][x][p[i]]=min(f[i+1][x][p[i]],f[i][x][y]+c[y][p[i+1]]);
			}
		}
	int res=0x3f3f3f3f;
	for(int i=1;i<=L;i++) for(int j=1;j<=L;j++) res=min(res,f[N][i][j]);
	printf("%d\n",res);
	return 0;
}