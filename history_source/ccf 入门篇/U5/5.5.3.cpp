#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	int Map[n][n]={0},x=0,y=0,i=1,j;
	for(j=0;j<n*n;j++)
	{
		if(i&1)
		{
			if(x>=0)
			{
				if(y<n) Map[x--][y++]=j+1;
				else x+=2,y--,i++,Map[x++][y--]=j+1;
			}
			else
			{
				if(y<n) x++,i++,Map[x++][y--]=j+1;
				else x+=2,y--,i++,Map[x++][y--]=j+1;
			}
		}
		else
		{
			if(y>=0)
			{
				if(x<n) Map[x++][y--]=j+1;
				else y+=2,x--,i++,Map[x--][y++]=j+1;
			}
			else
			{
				if(x<n) y++,i++,Map[x--][y++]=j+1;
				else y+=2,x--,i++,Map[x--][y++]=j+1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) printf("%d ",Map[j][i]);
		printf("\n");
	} 
	return 0;
}
