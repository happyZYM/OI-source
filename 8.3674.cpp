#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
const int maxm=2e5+5;
const int maxmem=2*(maxn*2+20*maxm);
int n,m,op,a,b,t[maxn];
struct Array
{
	int rtid,ncnt,rt[maxm],lc[maxmem],rc[maxmem],val[maxmem],p,upd;
	void build(int &o,int L,int R)
	{
		o=++ncnt;
		if(L==R) { val[o]=t[L]; return; }
		int M=(L+R)>>1;
		build(lc[o],L,M);
		build(rc[o],M+1,R);
	}
	int modify(int o,int L,int R)
	{
		int no=++ncnt;
		lc[no]=lc[o]; rc[no]=rc[o];
		if(L==R) { val[no]=upd; return no; }
		int M=(L+R)>>1;
		if(p<=M) lc[no]=modify(lc[no],L,M);
		else rc[no]=modify(rc[no],M+1,R);
		return no;
	}
	int query(int o,int L,int R)
	{
		if(L==R) return val[o];
		int M=(L+R)>>1;
		if(p<=M) return query(lc[o],L,M);
		else return query(rc[o],M+1,R);
	}
	void init()
	{
		rtid=ncnt=0;
		build(rt[0],1,n);
	}
	inline void CopyFrom(int id)
	{
		rt[++rtid]=rt[id];
	}
	inline int get(int id,int p)
	{
		this->p=p;
		return query(rt[rtid],1,n);
	}
	inline int set(int id,int p,int v)
	{
		this->p=p; upd=v;
		rtid++;
		rt[rtid]=modify(rt[rtid-1],1,n);
		return v;
	}
} fa,dep;
int ff(int id,int u)
{
	int v;
	while(v=fa.get(id,u),u!=v) u=v;
	return u;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	dep.init();
	for(int i=1;i<=n;i++) t[i]=i;
	fa.init();
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&op,&a);
		if(op==1)
		{
			scanf("%d",&b);
			a=ff(i-1,a);
			b=ff(i-1,b);
			int ad=dep.get(i-1,a),bd=dep.get(i-1,b);
			if(ad<bd) { swap(ad,bd); swap(a,b); }
			fa.set(i-1,b,a);
			if(ad==bd) dep.set(i-1,a,ad+1);
			else dep.CopyFrom(i-1);
		}
		else if(op==2)
		{
			fa.CopyFrom(a);
			dep.CopyFrom(a);
		}
		else
		{
			scanf("%d",&b);
			a=ff(i-1,a);
			b=ff(i-1,b);
			puts(a==b?"1":"0");
			fa.CopyFrom(i-1);
			dep.CopyFrom(i-1);
		}
	}
	return 0;
}
