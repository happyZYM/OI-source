#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cassert>
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
const int maxn=50005;
struct Query { int l,r,id; };
Query q[maxn];
int n,m,k,cnt[maxn],tot,a[maxn],res[maxn],bid[maxn];
inline bool cmp(const Query &a,const Query &b)
{ return bid[a.l]!=bid[b.l]?bid[a.l]<bid[b.l]:((bid[a.l]&1)?a.r<b.r:a.r>b.r); }
inline void Add(int v) { cnt[v]++; tot+=cnt[v]*2-1; }
inline void Del(int v) { cnt[v]--; tot-=cnt[v]*2+1; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n,m,k);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=m;i++) read(q[i].l,q[i].r),q[i].id=i;
	int blo=sqrt(n);
	for(int i=1;i<=n;i++) bid[i]=(i-1)/blo+1;
	sort(q+1,q+1+m,cmp);
	int l=q[1].l,r=q[1].r;
	for(int i=l;i<=r;i++) Add(a[i]);
	res[q[1].id]=tot;
	for(int i=2;i<=m;i++)
	{
		Query &Q=q[i];
		while(l<Q.l) Del(a[l++]);
		while(l>Q.l) Add(a[--l]);
		while(r>Q.r) Del(a[r--]);
		while(r<Q.r) Add(a[++r]);
		res[Q.id]=tot;
	}
	for(int i=1;i<=m;i++) printf("%d\n",res[i]);
	return 0;
}
