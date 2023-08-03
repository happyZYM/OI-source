#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
const int maxmem=2*(maxn*2+17*maxn);
int n,m,T,a[maxn],b[maxn],rt[maxn*2],lc[maxmem],rc[maxmem],cnt[maxmem],ncnt;
void build(int &o,int L,int R)
{
	o=++ncnt;
	if(L==R) return;
	int M=(L+R)>>1;
	build(lc[o],L,M);
	build(rc[o],M+1,R);
}
int modify(int o,int L,int R,int val)
{
	int no=++ncnt;
	lc[no]=lc[o]; rc[no]=rc[o]; cnt[no]=cnt[o]+1;
	if(L==R) return no;
	int M=(L+R)>>1;
	if(val<=M) lc[no]=modify(lc[o],L,M,val);
	else rc[no]=modify(rc[o],M+1,R,val);
	return no;
}
int query(int lrt,int rrt,int L,int R,int k)
{
	int M=(L+R)>>1,x=cnt[lc[rrt]]-cnt[lc[lrt]];
	if(L==R) return L;
	if(x>=k) return query(lc[lrt],lc[rrt],L,M,k);
	else return query(rc[lrt],rc[rrt],M+1,R,k-x);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) { cin>>a[i]; b[i]=a[i]; }
	sort(b+1,b+1+n);
	T=unique(b+1,b+1+n)-(b+1);
	build(rt[0],1,T);
	for(int i=1;i<=n;i++) rt[i]=modify(rt[i-1],1,T,lower_bound(b+1,b+1+n,a[i])-b);
	for(int i=1;i<=m;i++)
	{
		int L,R,k; cin>>L>>R>>k;
		cout<<b[query(rt[L-1],rt[R],1,T,k)]<<'\n';
	}
	return 0;
}
