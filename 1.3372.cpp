#include<cstdio>
const int maxn=100005;
int n,m,c;
typedef long long ll;
ll a[maxn];
int pl,pr;
ll v;
ll sumv[maxn<<2],addv[maxn<<2];
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
inline void push_up(int o)
{ sumv[o]=sumv[lc(o)]+sumv[rc(o)]; }
inline void f(int o,int L,int R,ll k)
{
	addv[o]+=k;
	sumv[o]+=k*(R-L+1);
}
inline void push_down(int o,int L,int R)
{
	int M=(L+R)>>1;
	f(lc(o),L,M,addv[o]);
	f(rc(o),M+1,R,addv[o]);
	addv[o]=0;
}
void build(int o,int L,int R)
{
	if(L==R) { sumv[o]=a[L]; return; }
	int M=(L+R)>>1;
	build(lc(o),L,M);
	build(rc(o),M+1,R);
	sumv[o]=sumv[lc(o)]+sumv[rc(o)];
	push_up(o);
}
void update(int o,int L,int R)
{
	if(pl<=L&&R<=pr) { f(o,L,R,v); return; }
	push_down(o,L,R);
	int M=(L+R)>>1;
	if(pl<=M) update(lc(o),L,M);
	if(pr>M) update(rc(o),M+1,R);
	push_up(o);
}
ll query(int o,int L,int R)
{
	ll res=0;
	if(pl<=L&&R<=pr) return sumv[o];
	int M=(L+R)>>1;
	push_down(o,L,R);
	if(pl<=M) res+=query(lc(o),L,M);
	if(pr>M) res+=query(rc(o),M+1,R);
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
	freopen("pro.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&c,&pl,&pr);
		if(c==1)
		{
			scanf("%lld",&v);
			update(1,1,n);
		}
		else printf("%lld\n",query(1,1,n));
	}
	return 0;
}
