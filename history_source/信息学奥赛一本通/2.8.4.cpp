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
char Map[25][25];
int x,y,bx,by;
struct BfS
{
	int xs,ys,step;
};
queue<BfS>bfs;
int dx[]={0,0,-1,1},
	dy[]={-1,1,0,0};
bool che(int xx,int yy)
{
	if(xx<0||xx>=x) return 0;
	if(yy<0||yy>=y) return 0;
	if(Map[xx][yy]=='#') return 0;
	return 1;
}
int answer()
{
	bfs.clear();
	BfS li;
	li.xs=bx;
	li.ys=by;
	li.step=1;
	bfs.push(li);
	while(bfs.size()>0)
	{
		for(int i=0;i<4;i++)
			if(che(bfs.front().xs+dx[i],bfs.front().ys+dy[i]))
			{
				if(Map[bfs.front().xs+dx[i]][bfs.front().ys+dy[i]]=='*') 
				return bfs.front().step;
				bfs.push(bfs.front());
				bfs.back().step++;
				bfs.back().xs+=dx[i];
				bfs.back().ys+=dy[i];
				Map[bfs.front().xs+dx[i]][bfs.front().ys+dy[i]]='#';
			}
		bfs.pop();
	}
	return -1;
}
int main()
{
	queue<int>ans;
	ans.beginning();
	bfs.beginning();
	while(true)
	{
		cin>>y>>x;
		if(y==0&&x==0) break;
		for(int i=0;i<y;i++)
			for(int j=0;j<x;j++)
			{
				cin>>Map[j][i];
				if(Map[j][i]=='@') bx=j,by=i;
			}
		ans.push(answer());
	}
	while(ans.size()>0)
	{
		cout<<ans.front()<<endl;
		ans.pop();
	}
	return 0;
}
