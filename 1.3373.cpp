#include<cstdio>
const int maxn=100005;
int n,m,c;
typedef long long ll;
ll p,a[maxn];
int pl,pr;
ll v;
ll sumv[maxn<<2],addv[maxn<<2],tmsv[maxn<<2];
inline void push_up(int o)
{ sumv[o]=(sumv[o<<1]+sumv[o<<1|1])%p; }
void build(int o,int L,int R)
{
	tmsv[o]=1;
	if(L==R) { sumv[o]=a[L]; return; }
	int M=(L+R)>>1,lc=o<<1,rc=o<<1|1;
	build(lc,L,M);
	build(rc,M+1,R);
	push_up(o);
}
inline void push_down(int o,int L,int R)
{
	int M=(L+R)>>1,lc=o<<1,rc=o<<1|1;
	tmsv[lc]=(tmsv[lc]*tmsv[o])%p;
	tmsv[rc]=(tmsv[rc]*tmsv[o])%p;
	addv[lc]=(addv[lc]*tmsv[o])%p;
	addv[rc]=(addv[rc]*tmsv[o])%p;
	sumv[lc]=(sumv[lc]*tmsv[o])%p;
	sumv[rc]=(sumv[rc]*tmsv[o])%p;
	tmsv[o]=1;
	addv[lc]=(addv[lc]+addv[o])%p;
	addv[rc]=(addv[rc]+addv[o])%p;
	sumv[lc]=(sumv[lc]+(M-L+1)*addv[o])%p;
	sumv[rc]=(sumv[rc]+(R-M)*addv[o])%p;
	addv[o]=0;
}
void add(int o,int L,int R)
{
	if(pl<=L&&R<=pr)
	{
		addv[o]=(addv[o]+v)%p;
		sumv[o]=(sumv[o]+(R-L+1)*v)%p;
		return;
	}
	int M=(L+R)>>1,lc=o<<1,rc=o<<1|1;
	if(tmsv[o]!=1||addv[o]) push_down(o,L,R);
	if(pl<=M) add(lc,L,M);
	if(pr>M) add(rc,M+1,R);
	push_up(o);
}
void tms(int o,int L,int R)
{
	if(pl<=L&&R<=pr)
	{
		addv[o]=(addv[o]*v)%p;
		tmsv[o]=(tmsv[o]*v)%p;
		sumv[o]=(sumv[o]*v)%p;
		return;
	}
	int M=(L+R)>>1,lc=o<<1,rc=o<<1|1;
	if(tmsv[o]!=1||addv[o]) push_down(o,L,R);
	if(pl<=M) tms(lc,L,M);
	if(pr>M) tms(rc,M+1,R);
	push_up(o);
}
ll query(int o,int L,int R)
{
	if(pl<=L&&R<=pr) return sumv[o]%p;
	ll res=0;
	int M=(L+R)>>1,lc=o<<1,rc=o<<1|1;
	if(tmsv[o]!=1||addv[o]) push_down(o,L,R);
	if(pl<=M) res+=query(lc,L,M);
	if(pr>M) res+=query(rc,M+1,R);
	return res%p;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
//	freopen("pro.out","w",stdout);
#endif
	scanf("%d%d%lld",&n,&m,&p);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&c,&pl,&pr);
		if(c==1)
		{
			scanf("%lld",&v);
			tms(1,1,n);
		}
		if(c==2)
		{
			scanf("%lld",&v);
			add(1,1,n);
		}
		if(c==3) printf("%lld\n",query(1,1,n));
	}
	return 0;
}
