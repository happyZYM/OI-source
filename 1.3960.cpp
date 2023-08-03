#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Node
{
	int s; LL L,R;
	Node* ch[2];
	inline void PU() { s=ch[0]->s+R-L+1+ch[1]->s; }
	inline int cmp(int k)
	{
		int d=k-ch[0]->s;
		return d>=1&&d<=R-L+1?-1:d>1;
	}
};
Node *null=new Node();
inline Node* NN(LL L,LL R)
{
	Node *o=new Node();
	o->L=L; o->R=R; o->s=R-L+1;
	o->ch[0]=o->ch[1]=null;
	return o;
}
inline void rotate(Node* &o,int d)
{
	Node* p=o->ch[d^1];
	o->ch[d^1]=p->ch[d]; p->ch[d]=o;
	o->PU();
	p->PU();
	o=p;
}
void Add(Node* &o,Node *v,int d)
{
	if(o==null) { o=v; return; }
	Add(o->ch[d],v,d);
	o->PU();
}
inline void cut(Node* &o,int k)
{
	LL L=o->L,R=o->R,s=R-L+1;
	o->L=o->R=L+k-1;
	if(k-1>=1) Add(o->ch[0],NN(L,L+k-2),1);
	if(k+1<=s) Add(o->ch[1],NN(L+k,R),0);
	o->PU();
}
void splay(Node* &o,int k)
{
	int d=o->cmp(k);
	if(d==-1&&o->R-o->L+1>1) cut(o,k);
	if(d==1) k-=o->ch[0]->s+1;
	if(d!=-1)
	{
		Node *p=o->ch[d];
		int d2=p->cmp(k);
		if(d2==-1&&p->R-p->L+1>1) cut(p,k);
		if(d2==1) k-=p->ch[0]->s+1;
		if(d2!=-1)
		{
			splay(p->ch[d2],k);
			if(d==d2) rotate(o,d^1);
			else rotate(o->ch[d],d);
		}
		rotate(o,d^1);
	}
}
inline Node* merge(Node *left,Node *right)
{
	splay(left,left->s);
	left->ch[1]=right;
	left->PU();
	return left;
}
inline void split(Node *o,int k,Node* &left,Node* &right)
{
	splay(o,k);
	left=o;
	right=o->ch[1];
	o->ch[1]=null;
	left->PU();
}
inline void dfsx(Node* o)
{
	if(o==null) return;
	dfsx(o->ch[0]);
	for(int i=o->L;i<=o->R;i++) printf("%d ",i);
	dfsx(o->ch[1]);
}
#define print(x) do { printf("%s: ",#x); dfsx(x); puts(""); } while(0)
//以上为splay模板
const int maxn=3e5+5;
LL n,m,q;
Node *r[maxn],*lst;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	null->ch[0]=null->ch[1]=null; null->s=0;
	dfsx(null);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		if(m>=2) r[i]=merge(NN(-1,-1),NN((i-1)*m+1,(i-1)*m+1+m-2));
		else r[i]=NN(-1,-1);
	}
	lst=NN(-1,-1);
	for(int i=1;i<=n;i++) lst=merge(lst,NN(i*m,i*m));
	for(int i=1;i<=q;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		if(y<m)
		{
			Node *a,*b,*c,*d,*e,*f;
			split(r[x],y,a,b);
			split(b,1,b,c);
			split(lst,x,d,e);
			split(e,1,e,f);
			printf("%lld\n",b->L);
			r[x]=merge(merge(a,c),e);
			lst=merge(merge(d,f),b);
		}
		else
		{
			Node *a,*b,*c;
			split(lst,x,a,b);
			split(b,1,b,c);
			printf("%lld\n",b->L);
			lst=merge(merge(a,c),b);
		}
	}
	return 0;
}
