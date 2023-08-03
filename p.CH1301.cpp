//http://contest-hunter.org:83/contest/0x10%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E4%BE%8B%E9%A2%98/1301%20%E9%82%BB%E5%80%BC%E6%9F%A5%E6%89%BE
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
const int oo=2e9;
int n,a[maxn],rk[maxn],rv[maxn],rp[maxn];
inline bool cmp(int x,int y) { return a[x]<a[y]; }
struct Node 
{
	int v,id;
	Node *pre,*nxt;
}mem[maxn],*mcnt=mem,*pos[maxn];
Node *head,*tail;
inline void init()
{
	head=mcnt++; tail=mcnt++;
	head->nxt=tail;
	tail->pre=head;
}
inline Node* insert(Node* p,int val,int id)
{
	Node *q=mcnt++;
	q->v=val; q->id=id;
	p->nxt->pre=q;
	q->nxt=p->nxt;
	p->nxt=q; q->pre=p;
	return q;
}
inline void remove(Node *p)
{
	p->pre->nxt=p->nxt;
	p->nxt->pre=p->pre;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	init();
	Node *p=head;
	for(int i=1;i<=n;i++) 
	{
		p=insert(p,a[rk[i]],rk[i]);
		pos[rk[i]]=p;
	}
	for(int i=n;i>=2;i--)
	{
		Node *p=pos[i];
		int pr=(p->pre!=head?abs(a[i]-p->pre->v):oo),nx=(p->nxt!=tail?abs(a[i]-p->nxt->v):oo);
		rv[i]=min(pr,nx);
		if(pr<nx) rp[i]=p->pre->id;
		else if(pr>nx) rp[i]=p->nxt->id;
		else rp[i]=(p->pre->v < p->nxt->v ? p->pre->id : p->nxt->id);
		remove(p);
	}
	for(int i=2;i<=n;i++) printf("%d %d\n",rv[i],rp[i]);
	return 0;
}
