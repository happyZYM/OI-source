#include<cstdio>
using namespace std;
int add=0;
struct Node
{
	int num;
	Node *next;
	Node()
	{
		next=NULL;
		num=0;
	}
};
int answer(int n,int m)
{
	Node *head,*last,*p,*x;
	head=new Node;
	head->num=1;
	last=head;
	for(int i=2;i<=n;i++)
	{
		last->next=new Node;
		last=last->next;
		last->num=i;
	}
	last->next=head;
	p=last;
	for(int i=0;i<n-1;i++)
	{
		for(int j=1;j<=m-1;j++) p=p->next;
		x=p;
		p=p->next;
		x->next=p->next;
//		printf("%d\n",p->num);
		delete p;
		p=x;
	}
	return p->num;
}
int main()
{
	Node *ans,*last;
	ans=new Node;
	last=ans;
	int m,n,x;
	while(true)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		x=answer(n,m);
		last->num=x;
		last->next=new Node;
		last=last->next;
	}
	while(ans!=last)
	{
		printf("%d\n",ans->num);
		ans=ans->next;
	}
	return 0;
}
/*
6 2
12 4
8 3
0 0
*/
