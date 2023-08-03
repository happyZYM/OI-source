#include<cstdio>
#include<queue>
using namespace std;
struct node
{
	int x,y;
	node(int xx,int yy){x=xx,y=yy;}
	node(){}
};
char map[105][105];
int xx,yy,sx,sy,ex,ey,dis[105][105],dx[]={0,0,-1,1},dy[]={-1,1,0,0};
inline int min(int a,int b){return a<b?a:b;}
int bfs()
{
	queue<node>que;
	node p;
	que.push(node(sx,sy));
	for(int i=0;i<yy;i++)
		for(int j=0;j<xx;j++) dis[j][i]=100000000;
	dis[sx][sy]=0;
	while(que.size()>0)
	{
		p=que.front();que.pop();
		if(p.x==ex&&p.y==ey) return dis[ex][ey];
		for(int i=0;i<4;i++)
			if(p.x+dx[i]>=0&&p.x+dx[i]<xx&&p.y+dy[i]>=0&&p.y+dy[i]<yy&&map[p.x+dx[i]][p.y+dy[i]]!='#'&&dis[p.x+dx[i]][p.y+dy[i]]==100000000)
			{
				que.push(node(p.x+dx[i],p.y+dy[i]));
				dis[p.x+dx[i]][p.y+dy[i]]=dis[p.x][p.y]+1;
			}
	}
}
void solve()
{
	printf("%d\n",bfs());
}
void init()
{
	scanf("%d%d",&xx,&yy);
	for(int i=0;i<yy;i++)
	{
		getchar();
		for(int j=0;j<xx;j++)
		{
			map[j][i]=getchar();
			if(map[j][i]=='S') sx=j,sy=i;
			if(map[j][i]=='G') ex=j,ey=i;
		}
	}
}
int main()
{
	init();
	solve();
	return 0;
}
