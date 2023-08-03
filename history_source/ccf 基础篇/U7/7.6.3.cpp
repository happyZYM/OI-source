#include<cstdio>
int n,a[305][305],y[305][305],maxn,max,i,j,k;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&(a[j][i]));
	for(i=0;i<n;i++)
		for(j=1;j<=n;j++)
			y[i][j]=y[i][j-1]+a[i][j-1];
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			maxn=0;
			for(k=0;k<n;k++)
			{
				if(maxn<0) maxn=y[k][j]-y[k][i-1];
				else maxn+=y[k][j]-y[k][i-1];
				if(maxn>max) max=maxn;
			}
		}
	printf("%d\n",max);
	return 0;
}
/*
4
0 -2 -7 0 
9 2 -6 2
-4 1 -4 2
-1 8 0 -2
*/
