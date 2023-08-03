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
		int size()
		{
			return SIZE_queue;
		}
		void operator()()
		{
			beginning();
		}
	};
}
using myDef::queue;
void swap(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}
bool answer(int a,int b)
{
	if(int(a/b)>=2) return 1;
	a-=b;
	if(a==0) return 1;
	if(a<b) swap(a,b);
	if(int(a/b)>=2) return 0;
	a-=b;
	if(a<b) swap(a,b);
	return answer(a,b);
}
int main()
{
	queue<bool>ans;
	ans();
	int a,b;
	while(true)
	{
		scanf("%d%d",&a,&b);
		if(a==0&&b==0) break;
		if(a<b) swap(a,b);
		ans.push(answer(a,b));
	}
	while(ans.size()>0)
	{
		if(ans.front()) printf("win\n");
		else printf("lose\n");
		ans.pop();
	}
	return 0;
}
