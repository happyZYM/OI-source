#include<cstdio>
using namespace std;
int main()
{
	int y,x;
	scanf("%d%d",&y,&x);
	int a[x][y],same=0;
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			scanf("%d",&a[j][i]);
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
		{
			int x;
			scanf("%d",&x);
			if(x==a[j][i]) same++;
		}
	printf("%.2lf\n",(double)same*100/(x*y));
	return 0;
}

