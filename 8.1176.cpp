#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxM=160005;
const int maxQ=10005;
const int maxW=2000005;
int S,W,M,Q,cnt;
struct MODI { int id,x,y,a; } modi[maxM];
struct QUE { int id,x,y; LL res; } que[maxQ*4];
struct Data { int id,t,x,y,a; LL res; } p[maxM+maxQ*4],t[maxM+maxQ*4];
bool cmp1(const Data &a,const Data &b) { return a.id<b.id; }
bool cmp2(const Data &a,const Data &b)
{
	if(a.t!=b.t) return a.t>b.t;
	return a.id<b.id;
}
inline void AddQ(int x,int y)
{
	Q++;
	que[Q].id=++cnt;
	que[Q].x=x;
	que[Q].y=y;
}
LL c[maxW];
void add(int p,LL v)
{
	for(;p<=W;p+=(p&-p)) c[p]+=v;
}
LL sum(int p)
{
	LL res=0;
	for(;p;p-=(p&-p)) res+=c[p];
	return res;
}
void CDQ(int L,int R)
{
	if(L==R) return;
	int M=(L+R)>>1,pl=L,pr=M+1,tot=L;
	CDQ(L,M);
	CDQ(M+1,R);
	while(pl<=M&&pr<=R)
	{
		if(p[pl].x<=p[pr].x)
		{
			if(p[pl].t==1) add(p[pl].y,p[pl].a);
			t[tot++]=p[pl++];
		}
		else
		{
			if(p[pr].t==2) p[pr].res+=sum(p[pr].y);
			t[tot++]=p[pr++];
		}
	}
	while(pl<=M)
	{
		if(p[pl].t==1) add(p[pl].y,p[pl].a);
		t[tot++]=p[pl++];
	}
	while(pr<=R)
	{
		if(p[pr].t==2) p[pr].res+=sum(p[pr].y);
		t[tot++]=p[pr++];
	}
	for(int i=L;i<=M;i++) if(p[i].t==1) add(p[i].y,-p[i].a);
	for(int i=L;i<=R;i++) p[i]=t[i];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&S,&W);
	int op,x1,y1,x2,y2,a;
	while(scanf("%d",&op),op!=3)
		if(op==1)
		{
			scanf("%d%d%d",&x1,&y1,&a);
			M++;
			modi[M].id=++cnt; modi[M].x=x1; modi[M].y=y1; modi[M].a=a;
		}
		else
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			AddQ(x2,y2);
			AddQ(x2,y1-1);
			AddQ(x1-1,y2);
			AddQ(x1-1,y1-1);
		}
	for(int i=1;i<=M;i++) p[i]=(Data){modi[i].id,1,modi[i].x,modi[i].y,modi[i].a,0ll};
	for(int i=1;i<=Q;i++) p[i+M]=(Data){que[i].id,2,que[i].x,que[i].y,0,0ll};
	sort(p+1,p+1+cnt,cmp1);
	CDQ(1,cnt);
	sort(p+1,p+1+cnt,cmp2);
	for(int i=1;i<=Q/4;i++)
	{
		LL a=p[i*4-3].res;
		LL b=p[i*4-2].res;
		LL c=p[i*4-1].res;
		LL d=p[i*4].res;
		printf("%d\n",int(a-b-c+d));
	}
	return 0;
}
