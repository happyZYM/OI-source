//http://contest-hunter.org:83/contest/0x18%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E7%BB%83%E4%B9%A0/1812%20%E7%94%9F%E6%97%A5%E7%A4%BC%E7%89%A9
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,m,a[maxn];
void Init()
{
	int tot=1,i=0; static int b[maxn];
	while(i<n&&a[i]<0) i++;
	if(i==n) { tot=0; return; }
	b[0]=a[i]; i++;
	for(;i<n;i++)
	{
		if((long long)a[i]*b[tot-1]>0) b[tot-1]+=a[i];
		else b[tot++]=a[i];
	}
	n=tot;
	for(int i=0;i<n;i++) a[i]=b[i];
	if(a[n-1]<0) n--;
}
struct Node
{
	int val; bool alive;
	Node *pre,*nxt; 
};
struct Data
{
	int val; Node *p;
};
priority_queue<Data> Q;
inline bool operator<(const Data &a,const Data &b) { return a.val>b.val; }
Node mem[maxn],*mcnt=mem,*head,*tail,*p;
inline Node* InsertAfter(Node *p,int val)
{
	mcnt->val=val; mcnt->alive=true;
	mcnt->pre=p; mcnt->nxt=p->nxt;
	mcnt->nxt->pre=mcnt; mcnt->pre->nxt=mcnt;
	Q.push((Data){abs(val),mcnt});
//	printf("insert %d\n",abs(val));
	return mcnt++;
}
inline void Erase(Node *p)
{
	p->alive=false;
	p->pre->nxt=p->nxt;
	p->nxt->pre=p->pre;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
	freopen("pro.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0) { n--; i--; }
	}
	Init();
	if(n==0||m==0) { puts("0"); return 0; }
	head=mcnt++; tail=mcnt++; head->nxt=tail; tail->pre=head; p=head;
	for(int i=0;i<n;i++) 
	{
		p=InsertAfter(p,a[i]);
//		printf("%d : %d\n",i+1,a[i]);
	}
	p=head->nxt;
	while(n/2+1>m)
	{
//		printf("n=%d\n",n);
		Data u;
		while(u=Q.top(),Q.pop(),!u.p->alive);
	//	printf("choose %d\n",u.p->val);
		if(u.p==head->nxt) { Erase(u.p->nxt); Erase(u.p); }
		else if(u.p==tail->pre) { Erase(u.p->pre); Erase(u.p); }
		else
		{
			u.p->val += u.p->pre->val + u.p->nxt->val;
			Erase(u.p->pre); Erase(u.p->nxt);
			Q.push((Data){abs(u.p->val),u.p});
	//		printf("have %d new!\n",u.p->val);
		}
		n-=2;
	}
	int res=0;
	p=head->nxt;
	while(p!=tail) { res+=p->val>0?p->val:0; p=p->nxt; }
	printf("%d\n",res);
	return 0;
}
