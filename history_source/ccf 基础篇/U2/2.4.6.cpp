#include<iostream>
#include<string>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
struct Node
{
	int num;
	Node *next;
};
string a,b;
int maxn(int i,int j)
{
	int ans=0;
	for(;i<a.size()&&j<b.size()&&a[i]==b[j];i++,j++) ans++;
	return ans;
}
int answer()
{
	a=a+a.substr(0,a.size()-1);
	b=b+b.substr(0,b.size()-1);
	int ans=-1;
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			ans=max(ans,maxn(i,j));
	return ans;
}
int main()
{
//	freopen("in.txt","r",stdin);
	ios::sync_with_stdio(0);
	Node *head,*last,*p;
	head=last=new Node;
	while(true)
	{
		cin>>a>>b;
		if(a.size()==1||b.size()==1) break;
		last->num=answer();
		last->next=new Node;
		last=last->next;
	}
	p=head;
	while(p!=last)
	{
		cout<<p->num<<endl;
		p=p->next;
	}
	return 0;
}
