#include<cstdio>
int sq[100][100];
long long ans=0;
int main()
{
	int x,y;
	scanf("%d%d",&y,&x);
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			scanf("%d",&sq[j][i]);
	if(x==1)
	{
		if(y==1) ans=sq[0][0];
		else
			for(int i=0;i<y;i++) ans+=sq[0][i];
	}
	else
	{
		if(y==1)
			for(int i=0;i<x;i++) ans+=sq[i][0];
		else
		{
			for(int i=0;i<y;i++) ans+=sq[0][i]+sq[x-1][i];
			for(int i=1;i<x-1;i++) ans+=sq[i][y-1]+sq[i][0];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
