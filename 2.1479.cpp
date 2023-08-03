#include<cstdlib>
struct Node
{
	Node *ch[2];
	int r,v,s;
	Node(int v):v(v) { ch[0]=ch[1]=NULL; r=rand(); s=1; }
	inline bool operator<(const Node &b) const
	{
		return r<b.r;
	}
	inline int cmp(int x) const { return x==v?-1:x>=v; }
	inline void maintain()
	{
		s=1+(ch[0]!=NULL?ch[0]->s:0)+(ch[1]!=NULL?ch[1]->s:0);
	}
};
void rotate(Node* &o,int d)
{
	Node* k=o->ch[d^1];
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	o->maintain();k->maintain();
	o=k;
}
void insert(Node* &o,int x)
{
	if(o==NULL) o=new Node(x);
	else
	{
		int d=(x < o->v ? 0 : 1);
		insert(o->ch[d],x);
		if(o->ch[d]->r > o->r) rotate(o,d^1);
	}
	o->maintain();
}
void remove(Node* &o,int x)
{
	int d=o->cmp(x);
	if(d==-1)
	{
		Node* u=o;
		if(o->ch[0]!=NULL&&o->ch[1]!=NULL)
		{
			int d2= (o->ch[0]->r > o->ch[1]->r ? 1: 0);
			rotate(o,d2);
			remove(o->ch[d2],x);
		}
		else
		{
			if(o->ch[0]==NULL) o=o->ch[1];
			else o=o->ch[0];
			delete u;
		}
	}
	else remove(o->ch[d],x);
	if(o!=NULL) o->maintain();
}

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxcmd=500010;
struct Command
{
	char type;
	int x,p;
} cmds[maxcmd];
const int maxn=20010;
const int maxm=60010;
int n,m,w[maxn],f[maxm],t[maxm],rmvd[maxm];

int fa[maxn];
int ff(int x) { return fa[x]!=x?fa[x]=ff(fa[x]):x; }

Node* root[maxn];

int kth(Node *o,int k)
{
	if(o==NULL||k<=0||k > o->s) return 0;
	int s=(o->ch[1]==NULL?0:o->ch[1]->s);
	if(k==s+1) return o->v;
	else if(k<=s) return kth(o->ch[1],k);
	else return kth(o->ch[0],k-s-1);
}
void IstTree(Node* &src,Node* &dest)
{
	if(src->ch[0]!=NULL) IstTree(src->ch[0],dest);
	if(src->ch[1]!=NULL) IstTree(src->ch[1],dest);
	insert(dest,src->v);
	delete src;
	src=NULL;
}
void RmvTree(Node* &o)
{
	if(o->ch[0]!=NULL) RmvTree(o->ch[0]);
	if(o->ch[1]!=NULL) RmvTree(o->ch[1]);
	delete o;
	o=NULL;
}
void AddEdge(int x)
{
	int u=ff(f[x]),v=ff(t[x]);
	if(u!=v)
	{
		if(root[u]->s < root[v]->s)
		{
			fa[u]=v;
			IstTree(root[u],root[v]);
		}
		else
		{
			fa[v]=u;
			IstTree(root[v],root[u]);
		}
	}
}

int qcnt;
long long qtot;
void query(int x,int k)
{
	qcnt++;
	qtot+=kth(root[ff(x)],k);
}
void ChangeWeight(int x,int v)
{
	int u=ff(x);
	remove(root[u],w[x]);
	insert(root[u],v);
	w[x]=v;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int kase=0;
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		for(int i=1;i<=n;i++) scanf("%d",&w[i]);
		for(int i=1;i<=m;i++) scanf("%d%d",&f[i],&t[i]);
		memset(rmvd,0,sizeof(rmvd));
		
		int c=0;
		while(1)
		{
			char type;
			int x,p=0,v=0;
			scanf(" %c",&type);
			if(type=='E') break;
			scanf("%d",&x);
			if(type=='D') rmvd[x]=true;
			if(type=='Q') scanf("%d",&p);
			if(type=='C')
			{
				scanf("%d",&v);
				p=w[x];
				w[x]=v;
			}
			cmds[c++]=(Command){type,x,p};
		}
		
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
			if(root[i]!=NULL) RmvTree(root[i]);
			root[i]=new Node(w[i]);
		}
		for(int i=1;i<=m;i++)
			if(!rmvd[i]) AddEdge(i);
		
		qtot=qcnt=0;
		for(int i=c-1;i>=0;i--)
		{
			if(cmds[i].type=='D') AddEdge(cmds[i].x);
			if(cmds[i].type=='Q') query(cmds[i].x,cmds[i].p);
			if(cmds[i].type=='C') ChangeWeight(cmds[i].x,cmds[i].p);
		}
		printf("Case %d: %.6lf\n",++kase,qtot/(double)qcnt);
	}
	return 0;
}
