#include<iostream>
#include<cstring>
using namespace std;
template<class T_queue>
struct Node_queue
{
	T_queue num;
	Node_queue *next;
};
template<class a_queue>
struct queue
{
	Node_queue<a_queue> *head,*tail;
	int SIZE_queue;
	void beginning()
	{
		head=tail=new Node_queue<a_queue>;
		tail->next=head;
		SIZE_queue=0;
	}
	bool push(a_queue s)
	{
		SIZE_queue++;
		tail->num=s;
		if(tail->next==head)
		{
			tail->next=new Node_queue<a_queue>;
			tail->next->next=head;
			tail=tail->next;
			return 1;
		}
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
	a_queue front()
	{
		return head->num;
	} 
	int size()
	{
		return SIZE_queue;
	}
};
int main()
{
	int n,q,x,y,b;
	ios::sync_with_stdio(0);
	queue<int>ans;
	ans.beginning();
	cin>>n>>q;
	int train[n+1],front[n+1];
	memset(train,-1,n+1);
	memset(front,-1,n+1);
	for(int i=1;i<=n;i++) 
	{
		cin>>x;
		train[i]=x;
		front[x]=i;
	}
	for(int i=0;i<q;i++)
	{
		cin>>b;
		if(b==0)
		{
			cin>>x;
			train[front[x]]=train[x];
			train[x]=-1;
		}
		else
		{
			cin>>x>>y;
			int n=x;
			for(int i=0;i<y;i++) n=train[n];
			ans.push(n==0?-1:n);
		}
	}
	while(ans.size()>0)
	{
		cout<<ans.front()<<endl;
		ans.pop();
	}
	return 0;
}
