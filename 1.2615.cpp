#include<cstdio>
using namespace std;
const int maxn=45;
int n,a[maxn][maxn];
int main()
{
	scanf("%d",&n);
	a[0][n/2]=1;
	int r=0,c=n/2;
	for(int i=2;i<=n*n;i++)
	{
		if(r==0&&c!=n-1) a[r=n-1][++c]=i;
		else if(c==n-1&&r!=0) a[--r][c=0]=i;
		else if(r==0&&c==n-1) a[++r][c]=i;
		else
		{
			if(!a[r-1][c+1]) a[--r][++c]=i;
			else a[++r][c]=i;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
