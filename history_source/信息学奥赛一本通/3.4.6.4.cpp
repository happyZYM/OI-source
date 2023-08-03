#include<cstdio>
int X,Y;
#define hh(a,b) ((a)*1001+(b))
int fa[1005000];
int ff(int n)
{
	int a,b;
	a=n;
	while(n!=fa[n]) n=fa[n];
	while(a!=n)
	{
		b=fa[a];
		fa[a]=n;
		a=b;
	}
	return n;
}
int main()
{
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	scanf("%d%d",&Y,&X);
	int i,j,x1,y1,x2,y2;
	for(i=1;i<=Y;i++)
		for(j=1;j<=X;j++)
			fa[hh(j,i)]=hh(j,i);
	while(scanf("%d%d%d%d",&y1,&x1,&y2,&x2)==4)
		if(ff(hh(x1,y1))!=ff(hh(x2,y2)))
			fa[ff(hh(x2,y2))]=ff(hh(x1,y1));
	int spend=0;
	for(i=1;i<Y;i++)
		for(j=1;j<=X;j++)
			if(ff(hh(j,i))!=ff(hh(j,i+1)))
			{
				spend++;
				fa[ff(hh(j,i))]=ff(hh(j,i+1));
			}
	for(i=1;i<=Y;i++)
		for(j=1;j<X;j++)
			if(ff(hh(j,i))!=ff(hh(j+1,i)))
			{
				spend+=2;
				fa[ff(hh(j,i))]=ff(hh(j+1,i));
			}
	printf("%d\n",spend);
	return 0;
}
