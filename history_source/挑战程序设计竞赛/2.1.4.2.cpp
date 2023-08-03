#include<cstdio>
int xx,yy;
char field[105][105];
void dfs(int x,int y)
{
	field[x][y]='.';
	int dx,dy,nx,ny;
	for(dx=-1;dx<=1;dx++)
		for(dy=-1;dy<=1;dy++)
		{
			nx=x+dx,ny=y+dy;
			if(0<=nx&&nx<xx&&0<=ny&&ny<yy&&field[nx][ny]=='W') dfs(nx,ny);
		}
}
void solve()
{
	int res=0,i,j;
	for(i=0;i<yy;i++)
		for(j=0;j<xx;j++)
			if(field[j][i]=='W')
			{
				dfs(j,i);
				res++;
			}
	printf("%d\n",res);
}
void init()
{
	scanf("%d%d",&yy,&xx);
	for(int i=0;i<yy;i++)
	{
		getchar();
		for(int j=0;j<xx;j++) field[j][i]=getchar();
	}
}
int main()
{
	init();
	solve();
	return 0;
}
