#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
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
const int maxn=400005;
using namespace std;
struct Data{int a,p;};
struct Q{int l,r,p;};
int n,m,nowm,rk_cnt,rk[maxn],cnt[maxn],res[maxn],num[maxn];
int blo,bid[maxn];
bool cmp1(const Data &a,const Data &b) { return a.a<b.a||(a.a==b.a&&a.p<b.p); }
inline bool cmp2(const Q &a,const Q &b)
{ return bid[a.l]!=bid[b.l]?a.l<b.l:((bid[a.l]&1)?a.r<b.r:a.r>b.r); }
Data a[maxn];
Q q[maxn];
inline void Add(int x)
{
	int d=num[x];
	if(nowm==d) nowm++;
	cnt[d]--; cnt[d+1]++; num[x]++;
}
inline void Del(int x)
{
	int d=num[x];
	if(nowm==d&&cnt[d]==1) nowm--;
	cnt[d]--; cnt[d-1]++; num[x]--;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    read(n,m);
    for(int i=1;i<=n;i++) read(a[i].a),a[i].p=i;
    sort(a+1,a+n+1,cmp1);
    for(int i=1;i<=n;i++)
    {
        if(i==1||a[i].a!=a[i-1].a) rk_cnt++;
        rk[a[i].p]=rk_cnt;
    }
    blo=sqrt(n);
    for(int i=1;i<=n;i++) bid[i]=(i-1)/blo+1;
    for(int i=1;i<=m;i++) read(q[i].l,q[i].r),q[i].p=i;
    sort(q+1,q+m+1,cmp2);
    int l=1,r=0; cnt[0]=rk_cnt;
    for(int i=1;i<=m;i++)
    {
        while(r<q[i].r) Add(rk[++r]);
        while(r>q[i].r) Del(rk[r--]);
        while(l<q[i].l) Del(rk[l++]);
        while(l>q[i].l) Add(rk[--l]);
        res[q[i].p]=-nowm;
    }
    for(int i=1;i<=m;i++) printf("%d\n",res[i]);
    return 0;
}
