#include<cstdio>
#include<cstring>
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
		queue()
		{
			beginning();
		} 
		queue(a_queue *left,a_queue *right)
		{
			beginning();
			a_queue *p=left;
			while(p!=right)
			{
				push(*p);
				p++;
			}
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
struct BFS
{
	int floor;
	int step;
	BFS()
	{
		step=floor=0;
	}
	BFS(int step_,int floor_)
	{
		floor=floor_;
		step=step_;
	}
};
queue<BFS>bfs;
int n,a,b;
bool *can;
int *num;
bool check(int floor)
{
	if(floor<=0||floor>n) return 0;
	return can[floor];
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	can=new bool[n+1];
	num=new int[n+1];
	num[0]=0;
	for(int i=1;i<=n;i++) scanf("%d",num+i);
	can[0]=0;
	memset(can+1,1,n);
	bfs.push(BFS(0,a));
	can[a]=0;
	if(a==b)
	{
		printf("0\n");
		return 0;
	}
	while(bfs.size()>0)
	{
		if(check(bfs.front().floor+num[bfs.front().floor]))
		{
			bfs.push(BFS(bfs.front().step+1,bfs.front().floor+num[bfs.front().floor]));
			if(bfs.back().floor==b)
			{
				printf("%d\n",bfs.back().step);
				return 0;
			}
			can[bfs.back().floor]=0;
		}
		if(check(bfs.front().floor-num[bfs.front().floor]))
		{
			bfs.push(BFS(bfs.front().step+1,bfs.front().floor-num[bfs.front().floor]));
			if(bfs.back().floor==b)
			{
				printf("%d\n",bfs.back().step);
				return 0;
			}
			can[bfs.back().floor]=0;
		}
		bfs.pop();
	}
	printf("-1\n");
	return 0;
}
