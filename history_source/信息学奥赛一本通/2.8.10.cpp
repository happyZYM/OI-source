#include<iostream>
#include<cstring>
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
int len;
bool Map[310][310];
struct POINT
{
	int x,y;
};
struct BFS
{
	POINT site;
	int step;
};
BFS li;
queue<BFS>bfs;
POINT start_,end_;
bool che(int xx,int yy)
{
	if(xx<0||xx>=len) return 0;
	if(yy<0||yy>=len) return 0;
	return Map[xx][yy];
}
int dx[]={1,2,2,1,-1,-2,-2,-1},
	dy[]={-2,-1,1,2,2,1,-1,-2};
int answer()
{
	bfs.clear();
	memset(Map,1,sizeof(Map));
	if(start_.x==end_.x&&start_.y==end_.y) return 0;
	li.site=start_;
	li.step=0;
	bfs.push(li);
	while(bfs.size()>0)
	{
		li=bfs.front();
		for(int i=0;i<8;i++)
		{
			if(che(li.site.x+dx[i],li.site.y+dy[i]))
			{
				Map[li.site.x+dx[i]][li.site.y+dy[i]]=0;
				bfs.push(li);
				bfs.back().site.x+=dx[i];
				bfs.back().site.y+=dy[i];
				bfs.back().step++;
				if(li.site.x+dx[i]==end_.x&&li.site.y+dy[i]==end_.y) return li.step+1;
			}
		}
		bfs.pop();
	}
}
int main()
{
	bfs.beginning();
	int n;
	cin>>n;
	int ans[n];
	for(int i=0;i<n;i++)
	{
		cin>>len;
		cin>>start_.x>>start_.y;
		cin>>end_.x>>end_.y;
		ans[i]=answer();
	}
	for(int i=0;i<n;i++) cout<<ans[i]<<endl;
	return 0;
}
