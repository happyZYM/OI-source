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
};
queue<Point>BFS;
int n;
Point a,b,xx;
char Map[110][110]; 
int dx[4]={0,1,0,-1},
	dy[4]={-1,0,1,0};
bool check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<n&&Map[x][y]=='.') return 1;
	return 0;
}
bool findRoad()
{
	if(Map[a.x][a.y]=='#'||Map[b.x][b.y]=='#') return 0;
	BFS.clear();
	BFS.push(a);
	while(BFS.size()>0)
	{
		for(int i=0;i<n;i++)
		{
			if(check(BFS.front().x+dx[i],BFS.front().y+dy[i]))
			{
				if(BFS.front().x+dx[i]==b.x&&BFS.front().y+dy[i]==b.y) return 1;
				xx.x=BFS.front().x+dx[i];
				xx.y=BFS.front().y+dy[i];
				BFS.push(xx);
				Map[xx.x][xx.y]='#';
			}
		}
		BFS.pop();
	}
	return 0;
}
int main()
{
	BFS();
	int k;
	cin>>k;
	bool answer[k];
	for(int i=0;i<k;i++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>Map[j][i];
		cin>>a.y>>a.x>>b.y>>b.x;
		answer[i]=findRoad();
	}
	for(int i=0;i<k;i++) 
		if(answer[i]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	return 0;
}

