#include<cstdio>
using namespace std;
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int a[n][m],b[m][k],c[n][k];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]); 
	for(int i=0;i<m;i++)
		for(int j=0;j<k;j++)
			scanf("%d",&b[i][j]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			c[i][j]=0;
			for(int x=0;x<m;x++) c[i][j]=c[i][j]+a[i][x]*b[x][j];
		}
	} 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;
}
