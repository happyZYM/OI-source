#include<cstdio>
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
int main()
{
	long long lou[31]={0,1,2};
	for(int i=3;i<31;i++) lou[i]=lou[i-1]+lou[i-2];
	queue<int>sr;
	sr();
	int x;
	while((scanf("%d",&x))==1) sr.push(x);
	while(sr.size()>0)
	{
		printf("%lld\n",lou[sr.front()]);
		sr.pop();
	}
	return 0;
}

