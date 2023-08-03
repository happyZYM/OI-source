#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=300005;
struct Data { int id,x,y,t,res; };
bool cmp1(const Data &a,const Data &b) { return a.x<b.x||(a.x==b.x&&a.t<b.t); }
bool cmp2(const Data &a,const Data &b) { return a.x>b.x||(a.x==b.x&&a.t<b.t); }
bool cmp3(const Data &a,const Data &b) { return a.id<b.id; }
typedef bool (*CMP)(const Data &a,const Data &b);
const int bq=1000001;
int f1(const int &y) { return y+1; }
int f2(const int &y) { return bq-y; }
typedef int (*F)(const int &y);
CMP cmp; F f; int dx,dy;
int n,m,c[1000005];
Data a[maxn*2],t[maxn*2];
const int oo=2000004;
void init()
{
	for(int i=1;i<=bq;i++) c[i]=-oo;
	sort(a+1,a+1+n,cmp3);
}
inline void SetMax(int p,int v)
{
	for(;p<=bq;p+=(p&-p)) c[p]=max(c[p],v);
}
inline int Query(int p)
{
	int res=-oo;
	for(;p;p-=(p&-p)) res=max(res,c[p]);
	return res;
}
inline void Clear(int p)
{
	for(;p<=bq;p+=(p&-p))
		if(c[p]==-oo) break;
		else c[p]=-oo;
}
void CDQ(int L,int R)
{ if(L==R) return;
	int M=(L+R)>>1,pl=L,pr=M+1,tot=L;
	CDQ(L,M);
	CDQ(M+1,R);
	while(pl<=M&&pr<=R)
	{
		if(cmp(a[pl],a[pr]))
		{
			if(a[pl].t==1) SetMax(f(a[pl].y),dx*a[pl].x+dy*a[pl].y);
			t[tot++]=a[pl++];
		}
		else
		{
			if(a[pr].t==2) a[pr].res=min(a[pr].res,dx*a[pr].x+dy*a[pr].y-Query(f(a[pr].y)));
			t[tot++]=a[pr++];
		}
	}
	while(pl<=M)
	{
		if(a[pl].t==1) SetMax(f(a[pl].y),dx*a[pl].x+dy*a[pl].y);
		t[tot++]=a[pl++];
	}
	while(pr<=R)
	{
		if(a[pr].t==2) a[pr].res=min(a[pr].res,dx*a[pr].x+dy*a[pr].y-Query(f(a[pr].y)));
		t[tot++]=a[pr++];
	}
	for(int i=L;i<=M;i++) if(a[i].t==1) Clear(f(a[i].y));
	for(int i=L;i<=R;i++) a[i]=t[i];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) { scanf("%d%d",&a[i].x,&a[i].y); a[i].t=1; }
	for(int i=n+1;i<=n+m;i++) { scanf("%d%d%d",&a[i].t,&a[i].x,&a[i].y); }
	n+=m;
	for(int i=1;i<=n;i++) { a[i].id=i; a[i].res=oo; }
	init(); cmp=cmp1; f=f1; dx=1; dy=1;
	CDQ(1,n);
	init(); cmp=cmp1; f=f2; dx=1; dy=-1;
	CDQ(1,n);
	init(); cmp=cmp2; f=f2; dx=-1; dy=-1;
	CDQ(1,n);
	init(); cmp=cmp2; f=f1; dx=-1; dy=1;
	CDQ(1,n);
	sort(a+1,a+1+n,cmp3);
	for(int i=1;i<=n;i++) if(a[i].t==2) printf("%d\n",a[i].res);
	return 0;
}