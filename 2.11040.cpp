#include<cstdio>
int a[10][10];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		for(int i=0;i<9;i+=2)
			for(int j=0;j<=i;j+=2)
				scanf("%d",&a[i][j]);
		for(int i=0;i+2<9;i+=2)
			for(int j=0;j<=i;j+=2)
			{
				a[i+2][j+1]=(a[i][j]-a[i+2][j]-a[i+2][j+2])/2;
				a[i+1][j]=a[i+2][j]+a[i+2][j+1];
				a[i+1][j+1]=a[i+2][j+1]+a[i+2][j+2];
			}
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<=i;j++)
				printf("%s%d",j?" ":"",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
