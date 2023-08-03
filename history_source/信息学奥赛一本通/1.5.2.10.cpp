#include<cstdio>
int main()
{
	int x,y,sq[101][101];
	scanf("%d%d",&y,&x);
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			scanf("%d",&sq[j][i]);
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
			if(i==0||i==y-1||j==0||j==x-1) 
				printf("%d ",sq[j][i]);
			else
				printf("%d ",
				int(
				(sq[j][i]+sq[j+1][i]
				+sq[j][i+1]+sq[j-1][i]+sq[j][i-1]+2.5)
				/5));
		printf("\n");
	}
	return 0;
}
