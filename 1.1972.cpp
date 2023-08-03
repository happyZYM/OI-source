#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
template<typename T> inline void read(T& t)
{
    t=0; int ch,f=false;
    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
    if(ch=='-') f=true,ch=getchar();
    t=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+(ch^48);
    if(f) t=-t;
}
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
const int maxn=500005;
const int maxm=200005;
struct Query { int l,r,id; };
Query q[maxm];
int n,m,cnt[1000001],tot,a[maxn],res[maxm],bid[maxn];
inline bool cmp(const Query &a,const Query &b)
{ return bid[a.l]!=bid[b.l]?bid[a.l]<bid[b.l]:((bid[a.l]&1)?a.r<b.r:a.r>b.r); }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	read(m);
	for(int i=1;i<=m;i++) read(q[i].l,q[i].r),q[i].id=i;
	int blo=sqrt(n);
	for(int i=1;i<=n;i++) bid[i]=(i-1)/blo+1;
	sort(q+1,q+1+m,cmp);
	int l=q[1].l,r=q[1].r;
	for(int i=l;i<=r;i++) tot+=(++cnt[a[i]]==1);
	res[q[1].id]=tot;
	for(int i=2;i<=m;i++)
	{
		Query &Q=q[i];
		while(l<Q.l) tot-=(--cnt[a[l++]]==0);
		while(l>Q.l) tot+=(++cnt[a[--l]]==1);
		while(r>Q.r) tot-=(--cnt[a[r--]]==0);
		while(r<Q.r) tot+=(++cnt[a[++r]]==1);
		res[Q.id]=tot;
	}
	for(int i=1;i<=m;i++) printf("%d\n",res[i]);
	return 0;
}
