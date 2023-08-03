#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100005;
int n,m;
LL a[maxn<<2],sum[maxn<<2],tag[maxn<<2],pl,pr,upd;
inline void Add(int o,int L,int R,LL v)
{
	tag[o]+=v;
	sum[o]+=(R-L+1)*v;
}
#define Lc(o) (o<<1)
#define Rc(o) (o<<1|1)
inline void PushDown(int o,int L,int R)
{
	int M=(L+R)>>1;
	Add(Lc(o),L,M,tag[o]);
	Add(Rc(o),M+1,R,tag[o]);
	tag[o]=0;
}
inline void PushUp(int o)
{
	sum[o]=sum[Lc(o)]+sum[Rc(o)];
}
void build(int o,int L,int R)
{
	if(L==R) { sum[o]=a[L]; return; }
	int M=(L+R)>>1;
	build(Lc(o),L,M);
	build(Rc(o),M+1,R);
	PushUp(o);
}
void update(int o,int L,int R)
{
	if(pl<=L&&R<=pr) { Add(o,L,R,upd); return; }
	int M=(L+R)>>1;
	PushDown(o,L,R);
	if(pl<=M) update(Lc(o),L,M);
	if(pr>M) update(Rc(o),M+1,R);
	PushUp(o);
}
LL query(int o,int L,int R)
{
	if(pl<=L&&R<=pr) return sum[o];
	PushDown(o,L,R);
	LL res=0; int M=(L+R)>>1;
	if(pl<=M) res+=query(Lc(o),L,M);
	if(pr>M) res+=query(Rc(o),M+1,R);
	PushUp(o);
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n);
	while(m-->0)
	{
		char op; scanf("%s%lld%lld",&op,&pl,&pr);
		if(op=='C')
		{
			scanf("%lld",&upd);
			update(1,1,n);
		}
		else printf("%lld\n",query(1,1,n));
	}
	return 0;
}
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100005;
int n,m; LL a[maxn],s[maxn],c[2][maxn];
inline LL ask(int id,int x)
{
	LL res=0;
	for(;x;x-=(x&-x)) res+=c[id][x];
	return res;
}
inline void add(int id,int x,int y)
{
	for(;x<=n;x+=(x&-x)) c[id][x]+=y;
}
inline LL query(int x) { return s[x]+(x+1)*ask(0,x)-ask(1,x); }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	while(m-->0)
	{
		char op; int l,r,d; scanf("%s%d%d",&op,&l,&r);
		if(op=='C')
		{
			scanf("%d",&d);
			add(0,l,d);
			add(0,r+1,-d);
			add(1,l,l*d);
			add(1,r+1,-(r+1)*d);
		}
		else printf("%lld\n",query(r)-query(l-1));
	}
	return 0;
}
*/
