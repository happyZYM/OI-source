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
		a_queue& operator[](unsigned int w)
		{
			w=w%SIZE_queue;
			Node_queue<a_queue> *p=head;
			for(int i=0;i<w;i++) p=p->next;
			return p->num;
		}
		void operator()()
		{
			beginning();
		}
		bool empty()
		{
			return (SIZE_queue==0);
		}
		bool operator=(myDef::queue<a_queue>b)
		{
			if(!isn)
			{
				this->beginning();
				isn=1;
			}
			this->clear();
			Node_queue<a_queue> *p=b.head;
			while(p!=b.tail)
			{
				this->push(p->num);
				p=p->next;
			}
		}
	};
}
using myDef::queue;
struct Point
{
	int x,y;
}a;
int main()
{
	queue<int>answer;
	answer();
	queue<Point>bfs;
	bfs();
	char Map[25][25];
	int x,y;
	while(true)
	{
		bfs.clear();
		cin>>x>>y;
		if(x==0&&y==0) break;
		for(int i=0;i<y;i++)
			for(int j=0;j<x;j++)
			{
				cin>>Map[j][i];
				if(Map[j][i]=='@') a.x=j,a.y=i;
			}
		Map[a.x][a.y]='#';
		bfs.push(a);
		int ans=1;
		int dx[4]={0,1,0,-1},
			dy[4]={-1,0,1,0};
		while(bfs.size()>0)
		{
			for(int i=0;i<4;i++)
			{
				a=bfs.front();
				if(a.x+dx[i]>=0&&a.x+dx[i]<x
				&&a.y+dy[i]>=0&&a.y+dy[i]<y
				&&Map[a.x+dx[i]][a.y+dy[i]]=='.')
				{
					ans++;
					Map[a.x+dx[i]][a.y+dy[i]]='#';
					a.x+=dx[i];
					a.y+=dy[i];
					bfs.push(a);
				}
			}
			bfs.pop();
		}
		answer.push(ans);
	}
	while(answer.size()>0)
	{
		cout<<answer.front()<<endl;
		answer.pop();
	}
	return 0;
}

