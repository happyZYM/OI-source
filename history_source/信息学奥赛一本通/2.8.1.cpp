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
		void operator()()
		{
			beginning();
		}
	};
}
using myDef::queue;
char Map[35][35][35];
int x,y,z;
struct Point
{
	int x,y,z;
}a,b;
struct bFs
{
	Point num;
	int step;
};
queue<bFs>bfs;
int dx[6]={0,0,-1,1,0,0},
	dy[6]={0,0,0,0,-1,1},
	dz[6]={-1,1,0,0,0,0};
bool che(int xx,int yy,int zz)
{
	if(xx<0||xx>=x) return 0;
	if(yy<0||yy>=y) return 0;
	if(zz<0||zz>=z) return 0;
	if(Map[xx][yy][zz]=='#') return 0;
	return 1;
}
int answer()
{
	bfs.clear();
	bFs li;
	li.num=a;
	li.step=0;
	bfs.push(li);
	Point p;
	while(bfs.size()>0)
	{
		p=bfs.front().num;
		for(int i=0;i<6;i++)
		{
			if(che(p.x+dx[i],p.y+dy[i],p.z+dz[i]))
			{
				li.num.x=p.x+dx[i];
				li.num.y=p.y+dy[i];
				li.num.z=p.z+dz[i];
				li.step=bfs.front().step+1;
				bfs.push(li);
				if(p.x+dx[i]==b.x&&p.y+dy[i]==b.y&&p.z+dz[i]==b.z) return li.step;
				Map[li.num.x][li.num.y][li.num.z]='#';
			}
		}
		bfs.pop();
	}
	return -1;
}
int main()
{
	queue<int>ans;
	ans();
	bfs();
	while(true)
	{
		cin>>z>>y>>x;
		if(z==0&&y==0&&x==0) break;
		for(int i=0;i<z;i++)
		{
			for(int j=0;j<y;j++)
			{
				for(int k=0;k<x;k++)
				{
					cin>>Map[k][j][i];
					if(Map[k][j][i]=='S') a.x=k,a.y=j,a.z=i;
					if(Map[k][j][i]=='E') b.x=k,b.y=j,b.z=i;
				}
			}
		}
		ans.push(answer());
	}
	while(ans.size()>0)
	{
		if(ans.front()==-1) cout<<"Trapped!"<<endl;
		else cout<<"Escaped in "<<ans.front()<<" minute(s)."<<endl;
		ans.pop();
	}
	return 0;
}
