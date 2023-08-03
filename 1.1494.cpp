#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
struct Query
{
	int l,r,id;
	LL len;
}b[60000];
int a[60000],bl[60000],n,m,blo,cnt[60000];
LL A[60000],B[60000],tot;
inline bool cmp(const Query &a,const Query &b)
{
	if(bl[a.l]<bl[b.l]) return 1;
	if(bl[a.l]>bl[b.l]) return 0;
	if(bl[a.l]&1) return a.r<b.r;
	return a.r>b.r;
}
inline void add(int x) { tot+=((cnt[x]<<1)|1); cnt[x]++; }
inline void del(int x) { tot+=1-(cnt[x]<<1); cnt[x]--; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	int blo=n/sqrt(m*2/3);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i].l,&b[i].r);
		b[i].len=b[i].r-b[i].l+1; b[i].id=i; B[i]=1; bl[i]=(i-1)/blo+1;
	}
	sort(b+1,b+m+1,cmp);
	int l=b[1].l,r=b[1].r;
	for(int i=l;i<=r;i++) add(a[i]);
	LL fz,fm,g;
	if(tot!=b[1].len)
	{
		fz=tot-b[1].len; fm=b[1].len*(b[1].len-1); g=__gcd(fz,fm);
		A[b[1].id]=fz/g; B[b[1].id]=fm/g;
	}
	for(int i=2;i<=m;i++)
	{
		while(l<b[i].l) del(a[l++]);
		while(l>b[i].l) add(a[--l]); 
		while(r>b[i].r) del(a[r--]); 
		while(r<b[i].r) add(a[++r]); 
		if(b[i].len!=tot)
		{
			fz=tot-b[i].len; fm=b[i].len*(b[i].len-1);
			g=__gcd(fz,fm); A[b[i].id]=fz/g; B[b[i].id]=fm/g;
		}
	}
	for(int i=1;i<=m;i++) printf("%lld/%lld\n",A[i],B[i]);
	return 0;
}
