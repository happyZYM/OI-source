#include<cassert>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=100005;
int N,K,a[maxn],d[maxn];
struct Node { int val,flg; Node *pre,*nxt; };
Node mem[maxn],*mcnt=mem,*head,*tail;
struct DT { int val; Node *from; };
inline bool operator<(const DT &a,const DT &b) { return a.val>b.val; }
priority_queue<DT> Q;
inline Node* insert(int v,Node *p) // insert v after p and return v
{
	Node *q=mcnt++;
	Q.push((DT){v,q});
	q->val=v; q->flg=1;
	p->nxt->pre=q;
	q->nxt=p->nxt;
	p->nxt=q;
	q->pre=p;
	return q;
}
void remove(Node *p)
{
	if(p==head||p==tail) return;
	p->pre->nxt=p->nxt;
	p->nxt->pre=p->pre;
	p->flg=0;
}
void print()
{
	Node *p=head->nxt;
	printf("d:");
	while(p!=tail) { printf(" %d",p->val); p=p->nxt; }
	puts("");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) scanf("%d",&a[i]);
	for(int i=0;i<N-1;i++) d[i]=a[i+1]-a[i];
	head=mcnt++; tail=mcnt++;
	head->nxt=tail; tail->pre=head;
	Node *p=head;
	for(int i=0;i<N-1;i++) p=insert(d[i],p);
//	print();
	int res=0;
	for(int i=0;i<K;i++)
	{
		DT u;
		while(u=Q.top(),Q.pop(),u.from->flg==0);
		assert(u.from->flg); assert(u.val==u.from->val);
		res+=u.val;
		p=u.from;
		int t=p->pre->val + p->nxt->val - p->val,hav=(p->pre!=head&&p->nxt!=tail);
		remove(p->pre); remove(p->nxt);
		if(hav) { p->val=t; Q.push((DT){t,p}); }
		else remove(p);
//		printf("i=%d choose %d\n",i,u.val); print();
	}
	printf("%d\n",res);
	return 0;
}
//537092323
