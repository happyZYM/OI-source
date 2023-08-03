#include<cstdio>
#include<queue>
//#include<mydef/screen.h>
using namespace std;
struct node
{
	int x,y;
	node()
	{
		x=y=0;
	}
	node(int X,int Y)
	{
		x=X;
		y=Y;
	}
};
queue<node> que;
int w,h,x,y,ans;
char map[25][25];
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
void solve()
{
	while(que.size()>0) que.pop();
	ans=1;
	map[y][x]='#';
	que.push(node(x,y));
	node t;
	while(que.size()>0)
	{
		t=que.front();
		que.pop();
		for(int i=0;i<4;i++)
			if(t.x+dx[i]>=0&&t.x+dx[i]<w&&t.y+dy[i]>=0&&t.y+dy[i]<h&&map[t.y+dy[i]][t.x+dx[i]]=='.')
			{
				map[t.y+dy[i]][t.x+dx[i]]='#';
				ans++;
				que.push(node(t.x+dx[i],t.y+dy[i]));
			}
	}
//	SetColor(10);
	printf("%d\n",ans);
//	SetColor(15);
}
int main()
{
	int i,j;
	while(1)
	{
		scanf("%d%d",&w,&h);
		if(w==0||h==0) break;
		getchar();
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				map[i][j]=getchar();
				if(map[i][j]=='@') x=j,y=i;
			}
			getchar();
		}
		solve();
	}
	return 0;
}
