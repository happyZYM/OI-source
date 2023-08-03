#include<cstdio>
using namespace std;
int main()
{
	int x,y;
	scanf("%d%d",&y,&x);
	int a[x][y],ans[x][y],n;
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			scanf("%d",&a[j][i]);
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
		{
			scanf("%d",&n);
			ans[j][i]=a[j][i]+n;
		}
	for(int i=0;i<y;i++)
	{
		for(int j=-0;j<x;j++)
			printf("%d ",ans[j][i]);
		printf("\n");
	}
	return 0;
}

