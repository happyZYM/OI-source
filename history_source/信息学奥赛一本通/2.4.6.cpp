#include<iostream>
using namespace std;
struct Q
{
	char c;
	int site;
};
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
	ios::sync_with_stdio(0);
	string sr;
	queue<string>ss;
	ss();
	while(cin>>sr) ss.push(sr);
	Q zhan[sr.size()+10],x;
	int top;
	while(ss.size()>0)
	{
		top=0;
		sr=ss.front();
		ss.pop();
		for(int i=0;i<sr.size();i++)
		{
			if(sr[i]=='(')
			{
				x.c='(';
				x.site=i;
				zhan[top++]=x;
			}
			if(sr[i]==')')
			{
				if(top>0) 
				{
					if(zhan[top-1].c=='(') top--;
					else
					{
						x.c=')';
						x.site=i;
						zhan[top++]=x;
					}
				}
				else
				{
					x.c=')';
					x.site=i;
					zhan[top++]=x;
				}
			}
		}
		cout<<sr<<endl;
		int g=0;
		for(int i=0;i<top;i++)
		{
			for(;g<zhan[i].site;g++) cout<<' ';
			g++;
			cout<<((zhan[i].c)=='('?'$':'?');
		}
		cout<<endl;
	}
	return 0;
}
