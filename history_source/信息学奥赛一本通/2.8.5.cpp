#include<iostream>
#define maxn 40 
using namespace std;
struct Bfs
{
	int x,y,step;
};
int dx[4]={0,0,-1,1},
	dy[4]={-1,1,0,0};
int y,x;
Bfs bfs[maxn*maxn+100];
char Map[maxn+1][maxn+1];
bool che(int xx,int yy)
{
	if(xx<0||xx>=x) return 0;
	if(yy<0||yy>=y) return 0;
	if(Map[xx][yy]=='#') return 0;
	return 1;
}
int main()
{
	cin>>y>>x;
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			cin>>Map[j][i];
	int front=0,tail=0;
	Bfs li;
	li.x=li.y=0;
	li.step=1;
	bfs[tail++]=li;
	while(tail-front>0)
	{
		for(int i=0;i<4;i++)
		{
			if(che(bfs[front].x+dx[i],bfs[front].y+dy[i]))
			{
				bfs[tail++]=bfs[front];
				bfs[tail-1].x+=dx[i];
				bfs[tail-1].y+=dy[i];
				bfs[tail-1].step++;
				if(bfs[tail-1].x==x-1&&bfs[tail-1].y==y-1)
				{
					cout<<bfs[tail-1].step<<endl;
					return 0;
				}
				Map[bfs[front].x+dx[i]][bfs[front].y+dy[i]]='#';
			}
		}
		front++;
	}
	return 0;
}
