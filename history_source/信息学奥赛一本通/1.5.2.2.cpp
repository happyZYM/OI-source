#include<cstdio>
using namespace std;
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++) printf("(%d,%d) ",x,i);
	printf("\n");
	for(int i=1;i<=n;i++) printf("(%d,%d) ",i,y);
	printf("\n");
	int j=0;
	while(x-j>0&&y-j>0) j++;
	j--;
	for(;x-j<=n&&y-j<=n;j--)
		printf("(%d,%d) ",x-j,y-j);
	j=0;
	printf("\n");
	while(x+j<=n&&y-j>0) j++;
	j--;
	for(;x+j>0&&y-j<=n;j--)
		printf("(%d,%d) ",x+j,y-j);
	printf("\n");
	return 0;
}
