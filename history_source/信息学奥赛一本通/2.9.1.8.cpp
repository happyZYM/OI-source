#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
	int h;
	scanf("%d",&h);
	int tawer[h][h];
	for(int i=0;i<h;i++)
		for(int j=0;j<=i;j++)
			scanf("%d",&tawer[j][i]);
	for(int i=h-2;i>=0;i--)
		for(int j=0;j<=i;j++)
			tawer[j][i]+=max(tawer[j][i+1],tawer[j+1][i+1]);
	printf("%d\n",tawer[0][0]);
	return 0;
}
