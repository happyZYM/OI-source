#include<cstdio>
using namespace std;
bool isad(int x,int y,int a[5][5])
{
	for(int i=0;i<5;i++) if(a[i][y]>a[x][y]) return 0;
	for(int i=0;i<5;i++) if(a[x][i]<a[x][y]) return 0;
	return 1;
}
int main()
{
	int a[5][5];
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&a[j][i]);
	bool flag=1;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(isad(j,i,a))
			{
				printf("%d %d %d\n",i+1,j+1,a[j][i]);
				flag=0;
			}
	if(flag) printf("not found\n");
	return 0;
}

