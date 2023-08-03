#include<cstdio>
#include<cstring>
#define xMax 10
#define yMax 10
int Map[xMax+1][yMax+1],xs,ys,ans=0;
int dx[]={-2,-1, 1, 2,2,1,-1,-2},
	dy[]={-1,-2,-2,-1,1,2, 2, 1};
bool check(int x,int y)
{
	if((x<0||x>=xs)||(y<0||y>=ys)||(Map[x][y]>0)) return 0;
	return 1;
}
void dfs(int x,int y,int step)
{
	if(step>=xs*ys){ans++;return;}
	for(int i=0;i<8;i++)
		if(check(x+dx[i],y+dy[i]))
		{
			Map[x+dx[i]][y+dy[i]]=step+1;
			dfs(x+dx[i],y+dy[i],step+1);
			Map[x+dx[i]][y+dy[i]]=0;
		}
}
int main()
{
	int t;
	int x,y;
	scanf("%d",&t);
	int answer[t];
	for(int i=0;i<t;i++)
	{
		scanf("%d%d%d%d",&xs,&ys,&x,&y);
		memset(Map,ans=0,sizeof(Map));
		dfs(x,y,Map[x][y]=1);
		answer[i]=ans;
	}
	for(int i=0;i<t;i++) printf("%d\n",answer[i]);
	return 0;
}
