#include<iostream>
#include<string>
using namespace std;
struct Node
{
	string No,name,addr;
	double score;
	int age;
	char sex;
	Node *next=NULL,*front=NULL;
};
int main()
{
	Node head,last;
	head.next=&last;
	last.front=&head;
	string n;
	while(true)
	{
		cin>>n;
		if(n=="end") break;
		last.front->next=new Node;
		last.front->next->front=last.front;
		last.front->next->next=&last;
		last.front=last.front->next;
		last.front->No=n;
		cin>>n;
		last.front->name=n;
		cin>>last.front->sex;
		cin>>last.front->age;
		cin>>last.front->score;
		while(last.front->addr+=getchar()
		,last.front->addr[last.front->addr.size()-1]!='\n');
		last.front->addr.erase(last.front->addr.size()-1,1);
	}
	Node *p;
	p=last.front;
	while(p!=&head)
	{
		cout<<p->No<<" "<<p->name<<" "<<p->sex<<" "<<p->age<<" "<<p->score<<p->addr<<endl;
		p=p->front;
	} 
	return 0;
}
