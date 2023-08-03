#include<cstdio>
int n,m,i,j,k,a[5000]={0},g[5000][5000],s;
char as;
inline int min(int a,int b)
{return a<b?a:b;}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
	{
		s=0;
		as=1;
		while(as!='\n')
		{
			s++;
			scanf("%d",a+s);
			as=getchar();
		}
		for(j=1;j<=s-1;j++)
			for(k=j+1;k<=s;k++)
				g[a[j]][a[k]]=1;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(g[i][j]==0)  g[i][j]=100000;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	if (g[1][n]>=100000) printf("NO\n");
	else printf("%d",g[1][n]-1);
	return 0;
}
