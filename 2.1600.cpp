#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,m,k,t;
int map[25][25];
bool vis[25][25][25];
int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1};
struct Point
{
	int x,y;
	int step;
	int layer;
	Point(int x=1,int y=1,int step=0,int layer=0):x(x),y(y),step(step),layer(layer){}
};
int bfs()
{
	queue<Point> Q;
	memset(vis,0,sizeof(vis));
	Point a(1,1,0,0);
	Point end_point(n,m);
	Q.push(a);
	vis[1][1][0]=true;
	while(!Q.empty())
	{
		Point now=Q.front();
		Q.pop();
		if(now.x==end_point.x&&now.y==end_point.y)
			return now.step;
		for(int i=0; i<4; i++)
		{
			int x=dx[i]+now.x;
			int y=dy[i]+now.y;
			int layer=now.layer;
			if(map[x][y]) layer++;
			else layer=0;
			if(layer<=k&&!vis[x][y][layer]&&x>=1&&y>=1&&x<=n&&y<=m)
			{
				vis[x][y][layer]=true;
				Q.push(Point(x,y,now.step+1,layer));
			}
		}
	}
	return -1;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				scanf("%d",&map[i][j]);
		printf("%d\n",bfs());
	}
	return 0;
}
