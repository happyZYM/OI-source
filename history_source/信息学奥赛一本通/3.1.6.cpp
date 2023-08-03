#include<cstdio>
#include<map>
#include<cstdlib>
struct Node
{
	union
	{
		char f;
		int num;
	};
	bool flag;
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
	};
}
using myDef::queue;
using std::map;
map<char,int>opf;
queue<Node>back_operation;
char ops[45]={'\0'};
int top=0;
void error()
{
	printf("NO\n");
	exit(0);
}
bool isop(char n)
{
	switch(n)
	{
		case '+':return 1;
		case '-':return 1;
		case '*':return 1;
		case '/':return 1;
	}
	return 0;
}
void mid_to_back_operation()
{
	int num=0;
	char li,back='+';
	Node node;
	while(li=getchar(),li!='@')
	{
		if(li>='0'&&li<='9') 
		{
			num_op:
				if(num>=0) num=num*10+li-'0';
				else num=num*10-(li-'0');
		}
		else
		{
			if(isop(back)&&li=='-') 
			{
				li=getchar();
				back=li;
				if(!(li>='0'&&li<='9')) error();
				li-='0';
				li=-li;
				li+='0';
				goto num_op;
			}
			if(li=='(')
			{
				if(!isop(back)) error();
				ops[top++]=li;
			}
			else
			{
				if(back!=')')
				{
					node.num=num;
					node.flag=1;
					back_operation.push(node);
					num=0;
				}
			}
			if(li==')')
			{
				while(ops[top-1]!='(')
				{
					node.flag=0;
					node.f=ops[top-1];
					back_operation.push(node);
					top--;
				}
				top--;
			}
			if(li!='('&&li!=')')
			{
				if(isop(back)) error();
				while(top>0&&opf[li]<=opf[ops[top-1]])
				{
					node.f=ops[top-1];
					node.flag=0;
					back_operation.push(node);
					top--;
				}
				ops[top++]=li;
			}
		}
		back=li; 
	}
	if(back!=')') 
	{
		node.num=num;
		node.flag=1;
		back_operation.push(node);
	}
	while(top>=0)
	{
		node.flag=0;
		node.f=ops[top-1];
		back_operation.push(node);
		top--;
	}
}
int operation()
{
	int zhan[35],a,b;
	top=0;
	Node li;
	while(back_operation.size()>0)
	{
		li=back_operation.front();
		if(li.flag) zhan[top++]=li.num;
		else
		{
			a=zhan[top-2];
			b=zhan[top-1];
			top--;
			switch(li.f)
			{
				case '+':zhan[top-1]=a+b;break;
				case '-':zhan[top-1]=a-b;break;
				case '*':zhan[top-1]=a*b;break;
				case '/':
					if(b==0) error();
					zhan[top-1]=a/b;break;
			}
		}
		back_operation.pop();
	}
	return zhan[0];
}
int main()
{
	opf['*']=2;
	opf['/']=2;
	opf['+']=1;
	opf['-']=1;
	opf['(']=-1;
	mid_to_back_operation();
	printf("%d\n",operation());
	return 0;
}
