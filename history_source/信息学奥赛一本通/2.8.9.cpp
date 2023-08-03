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
		void clear()
		{
			SIZE_queue=0;
			tail=head;
		}
	};
}
using myDef::queue;
char Map[210][210];
struct Bfs{
	int x,y,step;
};
queue<Bfs>bfs;
int x,y,sx,sy;
bool che(int xx,int yy)
{
	if(xx<0||xx>=x) return 0;
	if(yy<0||yy>=y) return 0;
	if(Map[xx][yy]=='#') return 0;
	return 1;
}
int dx[]={0,0,-1,1},
	dy[]={-1,1,0,0};
int anss()
{
	bfs.clear();
	Bfs li;
	li.x=sx;
	li.y=sy;
	li.step=0;
	bfs.push(li);
	while(bfs.size()>0)
	{
		li=bfs.front();
		for(int i=0;i<4;i++)
		{
			if(che(li.x+dx[i],li.y+dy[i]))
			{
				bfs.push(li);
				bfs.back().x+=dx[i];
				bfs.back().y+=dy[i];
				bfs.back().step++;
				if(Map[bfs.back().x][bfs.back().y]=='E') return bfs.back().step;
				Map[bfs.back().x][bfs.back().y]='#';
			}
		}
		bfs.pop();
	}
	return -1;
}
int main()
{
	int t;
	cin>>t;
	int answer[t];
	bfs.beginning();
	for(int i=0;i<t;i++)
	{
		cin>>y>>x;
		for(int i=0;i<y;i++)
			for(int j=0;j<x;j++)
			{
				cin>>Map[j][i];
				if(Map[j][i]=='S') sx=j,sy=i;
			}
		answer[i]=anss();
	}
	for(int i=0;i<t;i++) 
	{
		if(answer[i]!=-1) cout<<answer[i]<<endl;
		else cout<<"oop!"<<endl;
	} 
	return 0;
}
