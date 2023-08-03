#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100005;
#define Lc (o<<1)
#define Rc (o<<1|1)
int n,m;
LL a[maxn],sum[maxn<<2]; int flg[maxn<<2],pl,pr;
void build(int o,int L,int R)
{
	if(L==R) { sum[o]=a[L]; flg[o]=(a[L]<=1); return; }
	int M=(L+R)>>1;
	build(Lc,L,M); build(Rc,M+1,R);
	sum[o]=sum[Lc]+sum[Rc];
	flg[o]=flg[Lc]&&flg[Rc];
}
void update(int o,int L,int R)
{
	if(flg[o]) return;
	if(L==R)
	{
		sum[o]=sqrt(sum[o]);
		flg[o]=(sum[o]<=1);
		return;
	}
	int M=(L+R)>>1;
	if(pl<=M) update(Lc,L,M);
	if(pr>M) update(Rc,M+1,R);
	sum[o]=sum[Lc]+sum[Rc];
	flg[o]=flg[Lc]&&flg[Rc];
}
LL query(int o,int L,int R)
{
	if(pl<=L&&R<=pr) return sum[o];
	LL res=0; int M=(L+R)>>1;
	if(pl<=M) res+=query(Lc,L,M);
	if(pr>M) res+=query(Rc,M+1,R);
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	while(m-->0)
	{
		int op,L,R; scanf("%d%d%d",&op,&L,&R);
		if(L>R) swap(L,R);
		pl=L; pr=R;
		if(op==0) update(1,1,n);
		else printf("%lld\n",query(1,1,n));
	}
	return 0;
}