#include<cstdio>
#include<queue>
#include<cstring>
//#include<conio.h>
using namespace std;
const int maxn=300;
char s[maxn];
struct Node
{
	bool have_value;
	int v;
	Node *left,*right;
	Node()
	{
		have_value=left=right=0;
		v=-1;
	}
};
Node* root;
bool failed;
inline Node* newnode()
{
	return new Node();
}
void addnode(int v,char* s)
{
//	printf("\ts=%s v=%d\n",s,v);
	int n=strlen(s);
	Node* u=root;
	for(int i=0;i<n-1;i++)
		if(s[i]=='L')
		{
			if(u->left==NULL) u->left=newnode();
			u=u->left;
		}
		else
		{
			if(u->right==NULL) u->right=newnode();
			u=u->right;
		}
	if(u->have_value)
	{
//		printf("\t\terror in 2!\n");
		failed=1;
	}
	u->v=v;
	u->have_value=1;
}
void remove_tree(Node*& u)
{
	if(u==NULL) return;
	remove_tree(u->left);
	remove_tree(u->right);
	delete u;
	u=NULL;
}
bool read_input()
{
	failed=0;
	remove_tree(root);
	root=newnode();
	while(1)
	{
		if(scanf("%s",s)!=1) return 0;
//		printf("\ts=%s\n",s);
		if(!strcmp(s,"()")) break;
		int v;
		sscanf(&s[1],"%d",&v);
		addnode(v,strchr(s,',')+1);
	}
	return 1;
}
void solve()
{
	queue<Node*> q;
	queue<int> ans;
	q.push(root);
	bool flag=0;
	while(q.size())
	{
		Node* u=q.front();q.pop();
		ans.push(u->v);
		if(!u->have_value)
		{
			failed=1;
//			printf("\t\terror in 1!\n");
		}
		if(u->left!=NULL) q.push(u->left);
		if(u->right!=NULL) q.push(u->right);
	}
	if(failed) printf("not complete\n");
	else
	{
		while(ans.size())
		{
			printf("%d",ans.front());
			ans.pop();
			if(ans.size()) printf(" ");
		}
		printf("\n"); 
	}
//	getch();
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(read_input()) solve();
	return 0;
}
