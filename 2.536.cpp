#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string s1,s2;
struct node
{
	char v;
	node *lch,*rch;
	node()
	{
		v=0;
		lch=rch=0;
	}
};
inline node* newnode()
{
	return new node();
}
int pos=0;
void solve(node*& root,string str,int step)
{
	if(str.size()==0||pos>=s1.size()) return;
//	for(int i=0;i<step;i++) printf("\t");
//	printf("input %s,root=%c\n",str.c_str(),s1[pos]);
	root=newnode();
	root->v=s1[pos];
	if(str.size()==1)
	{
		pos++;
		return;
	}
	int t=str.find(s1[pos]);
	pos++;
	solve(root->lch,str.substr(0,t),step+1);
	if(t+1<str.size()) solve(root->rch,str.substr(t+1),step+1);
}
void print(node* root)
{
	if(root==0) return;
	print(root->lch);
	print(root->rch);
	printf("%c",root->v);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(cin>>s1>>s2)
	{
		node* root=0;
		pos=0;
		solve(root,s2,0);
		print(root);
		printf("\n");
	}
	return 0;
}
/*
DBACEGF ABCDEFG


*/
