#include<cstdio>
#include<cstring>
int fa[1001],a[1001][1001],c[1001];
int find(int x)
{
	int r;
	r=x;
	while (fa[r]!=r) r=fa[r];
	return r;
}
int main()
{
	int n,m,s=0,i,j,k,x,y,z,r1,r2,t;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&z,&x,&y);
		if(z==0)
		{
			r1=find(x);
			r2=find(y);
			fa[r2]=r1;
		}
		if(z==1)
		{
			for(j=1;j<=a[x][0];j++)
			{
				r1=find(y);
				r2=find(a[x][j]);
				fa[r2]=r1;
			}
			for(j=1;j<=a[y][0];j++)
			{
				r1=find(x);
				r2=find(a[y][j]);
				fa[r2]=r1;
			}
			a[x][0]++;
			a[y][0]++;
			a[x][a[x][0]]=y;
			a[y][a[y][0]]=x;
		}
	}
	s=0;
	for(i=1;i<=n;i++) if(fa[i]==i) s++;
	printf("%d\n",s);
	return 0;
}
