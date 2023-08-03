#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=55;
const int maxlongint=64;
int n,m;
bool arv[maxn][maxn][maxlongint];
int d[maxn][maxn];
int main()
{
	scanf("%d%d",&n,&m);
	memset(d,0x3F,sizeof(d));
	for(int i=0;i<m;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		arv[u][v][0]=true; d[u][v]=1;
	}
	for(int k=1;k<maxlongint;k++)
		for(int M=1;M<=n;M++)
			for(int u=1;u<=n;u++)
				for(int v=1;v<=n;v++)
					if(arv[u][M][k-1]&&arv[M][v][k-1])
					{
						arv[u][v][k]=true;
						d[u][v]=1;
					}
	for(int M=1;M<=n;M++)
		for(int u=1;u<=n;u++)
			for(int v=1;v<=n;v++)
				d[u][v]=min(d[u][v],d[u][M]+d[M][v]);
	printf("%d\n",d[1][n]);
	return 0;
}
