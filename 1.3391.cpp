#include<cstdio>
#include<algorithm>
using namespace std;
struct Node
{
	int v,s; char f;
	Node* ch[2];
	inline int cmp(int k)
	{
		int d=k-ch[0]->s;
		return d==1?-1:d>1;
	}
	inline void push_up()
	{ s=ch[0]->s+1+ch[1]->s; }
	inline void push_down()
	{
		if(!f) return;
		swap(ch[0],ch[1]);
		ch[0]->f^=1;
		ch[1]->f^=1;
		f=0;
	}
};
Node* null=new Node();
inline void rotate(Node* &o,int d)
{
	Node* p=o->ch[d^1];
	o->ch[d^1]=p->ch[d]; p->ch[d]=o;
	o->push_up();
	p->push_up();
	o=p;
}
void splay(Node* &o,int k)
{
	o->push_down();
	int d=o->cmp(k);
	if(d==1) k-=o->ch[0]->s+1;
	if(d!=-1)
	{
		Node* &p=o->ch[d];
		p->push_down();
		int d2=p->cmp(k);
		if(d2==1) k-=p->ch[0]->s+1;
		if(d2!=-1)
		{
			splay(p->ch[d2],k);
			if(d==d2) rotate(o,d^1);
			else rotate(p,d);
		}
		rotate(o,d^1);
	}
}
Node* build(int L,int R)
{
	if(L>R) return null;
	Node* res=new Node();
	res->v=(L+R)>>1; res->f=0;
	if(L==R) res->ch[0]=res->ch[1]=null;
	else res->ch[0]=build(L,((L+R)>>1)-1),res->ch[1]=build(((L+R)>>1)+1,R);
	res->push_up();
	return res;
}
int n,m,a,b;
void print(Node* o)
{
	o->push_down();
	if(o==null) return;
	print(o->ch[0]);
	if(o->v>=1&&o->v<=n) printf("%d ",o->v);
	print(o->ch[1]);
}	
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
	freopen("pro.out","w",stdout);
#endif
	null->s=null->f=0; null->ch[0]=null->ch[1]=null;
	scanf("%d%d",&n,&m);
	Node* root=build(0,n+1);
	while(m-->0)
	{
		scanf("%d%d",&a,&b);
		splay(root,a);
		splay(root->ch[1],b+2-root->ch[0]->s-1);
		root->ch[1]->ch[0]->f^=1;
	}
	print(root);
	return 0;
}
