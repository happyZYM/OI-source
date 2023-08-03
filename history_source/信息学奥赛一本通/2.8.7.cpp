#include<iostream>
using namespace std;
namespace myDef
{
	template<class T_queue>
	struct Node_queue
	{
		T_queue num;
		Node_queue *next=0;
	};
	template<class a_queue>
	struct queue
	{
		Node_queue<a_queue> *head=0,*tail=0,*L=0;
		bool isn=0;
		int SIZE_queue;
		void beginning()
		{
			head=tail=new Node_queue<a_queue>;
			tail->next=head;
			SIZE_queue=0;
			isn=1;
		}
		bool push(a_queue s)
		{
			SIZE_queue++;
			tail->num=s;
			if(tail->next==head)
			{
				tail->next=new Node_queue<a_queue>;
				tail->next->next=head;
				L=tail;
				tail=tail->next;
				return 1;
			}
			L=tail;
			tail=tail->next;
			return 0;
		}
		bool pop()
		{
			if(head==tail) return 1;
			head=head->next;
			SIZE_queue--;
			return 0;
		} 
		a_queue& front()
		{
			return head->num;
		} 
		a_queue& back()
		{
			return L->num;
		}
		int size()
		{
			return SIZE_queue;
		}
	};
}
struct Point
{
	int xs,ys;
};
struct BFS
{
	Point node;
	int step;
};
using myDef::queue;
int x,y;
char Map[110][110];
bool che(int xx,int yy)
{
	if(xx<0||xx>=x) return 0;
	if(yy<0||yy>=y) return 0;
	if(Map[xx][yy]=='#') return 0;
	return 1;
}
int main()
{
	int dx[4]={0,0,-1,1},
		dy[4]={-1,1,0,0};
	Point s;
	cin>>y>>x;
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
		{
			cin>>Map[j][i];
			if(Map[j][i]=='S') s.xs=j,s.ys=i;
		}
	BFS li;
	li.node=s;
	li.step=0;
	queue<BFS>bfs;
	bfs.beginning();
	bfs.push(li);
	while(bfs.size()>0)
	{
		for(int i=0;i<4;i++)
		{
			li=bfs.front();
			if(che(li.node.xs+dx[i],li.node.ys+dy[i]))
			{
				li.node.xs+=dx[i];
				li.node.ys+=dy[i];
				li.step++;
				if(Map[li.node.xs][li.node.ys]=='T')
				{
					cout<<li.step<<endl;
					return 0;
				}
				Map[bfs.back().node.xs][bfs.back().node.ys]='#';
				bfs.push(li);
			}
		}
		bfs.pop();
	}
	return 0;
}
