#include<cstdio>
#include<algorithm>
using namespace std;
struct Node
{
	Node *ch[2];
	int s,v,flip;
	inline int cmp(int k)
	{
		int d=k-ch[0]->s;
		if(d==1) return -1;
		return d<=0?0:1;
	}
	inline void maintain()
	{
		s=ch[0]->s+ch[1]->s+1;
	}
	inline void pushdown()
	{
		if(!flip) return;
		flip=0;
		swap(ch[0],ch[1]);
		ch[0]->flip=!(ch[0]->flip);
		ch[1]->flip=!(ch[1]->flip);
	}
};
Node *null=new Node();
inline void rotate(Node* &o,int d)
{
	Node *k=o->ch[d^1];
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	o->maintain();
	k->maintain();
	o=k;
}
void splay(Node* &o,int k)
{
	o->pushdown();
	int d=o->cmp(k);
	if(d==1) k-=o->ch[0]->s+1;
	if(d!=-1)
	{
		Node *p=o->ch[d];
		p->pushdown();
		int d2=p->cmp(k);
		int k2=(d2==0?k:k - 1 - p->ch[0]->s );
		if(d2!=-1)
		{
			splay(p->ch[d2],k2);
			if(d==d2) rotate(o,d^1);
			else rotate(o->ch[d],d);
		}
		rotate(o,d^1);
	}
}
inline Node* merge(Node* left,Node* right)
{
	splay(left,left->s);
	left->ch[1]=right;
	left->maintain();
	return left;
}
inline void split(Node* o,int k,Node* &left,Node* &right)
{
	splay(o,k);
	left=o;
	right=o->ch[1];
	o->ch[1]=null;
	left->maintain();
}
const int maxn=101000;
struct STree
{
	int n;
	Node seq[maxn];
	Node *root;
	Node* build(int sz)
	{
		if(sz==0) return null;
		Node* L=build(sz/2);
		Node* o=&seq[++n];
		o->v=n;
		o->ch[0]=L;
		o->ch[1]=build(sz-sz/2-1);
		o->s=o->flip=0;
		o->maintain();
		return o;
	}
	void init(int sz)
	{
		n=0;
		null->s=0;
		root=build(sz);
	}
};
bool flag;
void print(Node* o)
{
	if(o!=null)
	{
		o->pushdown();
		print(o->ch[0]);
		if(flag) printf("%d\n",o->v-1);
		flag=true;
		print(o->ch[1]);
	}
}
STree ss;
int n,m,a,b;
Node *o,*mid,*left,*right;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	ss.init(n+1);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		split(ss.root,a,left,o);
		split(o,b-a+1,mid,right);
		mid->flip^=1;
		ss.root=merge(merge(left,right),mid);
	}
	print(ss.root);
	return 0;
}
