#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100005;
LL n,w,h,a[maxn<<1],cnt;
struct  Data
{
	LL x,y1,y2,c;
	Data() { }
	Data(LL _x,LL _y1,LL _y2,LL _c):x(_x),y1(_y1),y2(_y2),c(_c) { }
}
li[maxn<<1];
inline bool operator<(const Data &a,const Data &b) { return a.x<b.x||(a.x==b.x&&a.c<b.c); }
#define Lc(o) (o<<1)
#define Rc(o) (o<<1|1)
LL mx[maxn<<3],tag[maxn<<3],pl,pr,upd;
inline void Add(int o,int v)
{
	tag[o]+=v;
	mx[o]+=v;
}
inline void PushDown(int o)
{
	Add(Lc(o),tag[o]);
	Add(Rc(o),tag[o]);
	tag[o]=0;
}
inline void PushUp(int o)
{
	mx[o]=max(mx[Lc(o)],mx[Rc(o)]);
}
void update(int o,int L,int R)
{
	if(pl<=L&&R<=pr) { Add(o,upd); return; }
	int M=(L+R)>>1;
	PushDown(o);
	if(pl<=M) update(Lc(o),L,M);
	if(pr>M) update(Rc(o),M+1,R);
	PushUp(o);
}
void solve()
{
	LL res=0,x,y,c;
	cnt=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&c);
		li[i*2]=Data(x,y,y+h-1,c);
		li[i*2+1]=Data(x+w,y,y+h-1,-c);
		a[++cnt]=y; a[++cnt]=y+h-1;
	}
	sort(a+1,a+1+cnt);
	cnt=unique(a+1,a+1+cnt)-(a+1);
	sort(li,li+n*2);
	memset(mx,0,sizeof(mx)); memset(tag,0,sizeof(tag));
	for(int i=0;i<n*2;i++)
	{
		li[i].y1=lower_bound(a+1,a+1+cnt,li[i].y1)-a;
		li[i].y2=lower_bound(a+1,a+1+cnt,li[i].y2)-a;
		pl=li[i].y1; pr=li[i].y2; upd=li[i].c;
		update(1,1,cnt);
		res=max(res,mx[1]);
	}
	printf("%lld\n",res);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%lld%lld%lld",&n,&w,&h)==3) solve();
	return 0;
}
