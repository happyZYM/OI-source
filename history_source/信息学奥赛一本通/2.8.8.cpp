#include<iostream>
using namespace std;
bool Map[5][5];
struct BFS
{
	int x,y,last;
};
bool che(int x,int y)
{
	if(x<0||x>4) return 0;
	if(y<0||y>4) return 0;
	return Map[x][y];
}
BFS bfs[30];
int front=0,tail=0;
void print(int n)
{
	if(n==-1) return;
	print(bfs[n].last);
	printf("(%d,%d)\n",bfs[n].y,bfs[n].x);
}
int main()
{
	int dx[4]={0,0,-1,1},
		dy[4]={-1,1,0,0}; 
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			cin>>Map[j][i];
			Map[j][i]=!Map[j][i];
		}
	bfs[tail].x=bfs[tail].y=0;
	bfs[tail].last=-1;
	tail++;
	while(tail-front>0)
	{
		for(int i=0;i<4;i++)
		{
			if(che(bfs[front].x+dx[i],bfs[front].y+dy[i]))
			{
				Map[bfs[front].x+dx[i]][bfs[front].y+dy[i]]=0;
				bfs[tail]=bfs[front];
				bfs[tail].last=front;
				bfs[tail].x+=dx[i];
				bfs[tail].y+=dy[i];
				if(bfs[tail].x==4&&bfs[tail].y==4) 
				{
					print(tail);
					return 0;
				}
				tail++;
			}
		}
		front++;
	}
	return 0;
}
/*
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/
