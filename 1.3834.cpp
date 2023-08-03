#include<cstdio>
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
const int maxn=200010;
int n,m,a[maxn],b[maxn],rt[maxn];
int ncnt,p,tot[maxn<<5],lc[maxn<<5],rc[maxn<<5];
void build(int &o,int L,int R)
{
	o=++ncnt;
	if(L==R) return;
	int M=(L+R)>>1;
	build(lc[o],L,M); build(rc[o],M+1,R);
}
int modify(int o,int L,int R)
{
	int no=++ncnt;
	lc[no]=lc[o]; rc[no]=rc[o]; tot[no]=tot[o]+1;
	if(L==R) return no;
	int M=(L+R)>>1;
	if(p<=M) lc[no]=modify(lc[no],L,M);
	else rc[no]=modify(rc[no],M+1,R);
	return no;
}
int query(int lrt,int rrt,int L,int R,int k)
{
	int M=(L+R)>>1,x=tot[lc[rrt]]-tot[lc[lrt]];
	if(L==R) return L;
	if(x>=k) return query(lc[lrt],lc[rrt],L,M,k);
	else return query(rc[lrt],rc[rrt],M+1,R,k-x);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int l,r,k,ttv;
	read(n,m);
	for(int i=1;i<=n;i++) read(a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	ttv=unique(b+1,b+n+1)-(b+1);
	build(rt[0],1,ttv);
	for(int i=1;i<=n;i++)
	{
		p=lower_bound(b+1,b+ttv+1,a[i])-b;
		rt[i]=modify(rt[i-1],1,ttv);
	}
	while(m-->0)
	{
		read(l,r,k);
		printf("%d\n",b[query(rt[l-1],rt[r],1,ttv,k)]);
	}
	return 0;
}
