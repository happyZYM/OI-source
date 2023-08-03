#include<cstdio>
using namespace std;
struct Node
{
	int num;
	Node *next=NULL;
};
int main()
{
	Node head,*last,*p,*f;
	last=new Node;
	head.next=last;
	int n,x,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		last->num=x;
		last->next=new Node;
		last=last->next;
	}
	scanf("%d",&k);
	f=&head;
	p=head.next;
	while(p!=last)
	{
		if(p->num==k)
		{
			f->next=p->next;
			delete p;
			p=f;
		}
		f=p;
		p=p->next;
	}
	p=head.next;
	while(p!=last)
	{
		printf("%d ",p->num);
		p=p->next;
	}
	return 0;
}

