#include<cstdio>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a[m][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[j][i]);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
