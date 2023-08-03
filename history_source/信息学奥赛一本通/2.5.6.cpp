#include<cstdio>
bool b2[9],b[9][9];
char a[9][9];
int m,n,s;
void dfs(int x,int k)
{
	static int i,j;
	for(i=x;i<=m;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i][j]=='#'&&!b2[j])
			{
				b2[j]=1;
				if(k==n) s++;
				else dfs(i+1,k+1);
				b2[j]=0;
			}
		}
}
int main()
{
	int i,j;
	do
	{
		scanf("%d%d",&m,&n);
		getchar();
		s=0;
		if(m!=-1||n!=-1)
		{
			for(i=1;i<=m;i++)
			{
				for(j=1;j<=m;j++)
					a[i][j]=getchar();
				getchar();
			}
			dfs(1,1);
			printf("%d\n",s);
		}
	}while(m!=-1||n!=-1);
	return 0;
}
