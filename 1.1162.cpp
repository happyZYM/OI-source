#include<cstdio>
int mp[35][35],n;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void dfs(int x,int y,int fill)
{
	if(x<=0||y<=0||x>n||y>n||mp[x][y]!=0) return;
	mp[x][y]=fill;
	for(int i=0;i<4;i++)
		dfs(x+dx[i],y+dy[i],fill);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&(mp[j][i]));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(j==1||i==1||j==n||i==n) dfs(j,i,-1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dfs(j,i,2);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(mp[j][i]==-1) printf("0 ");
			else printf("%d ",mp[j][i]);
		printf("\n");
	}
	return 0;
}
