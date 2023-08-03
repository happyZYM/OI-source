#include<cstdio>
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
using namespace std;
const int maxn=1e6+5;
const int maxm=1e6+5;
int n,m,a[maxn];
int ncnt,rt[maxn],lc[maxn<<5],rc[maxn<<5],val[maxn<<5];
int v,opt,idx,nval;
void build(int &o,int L,int R)
{
	o=++ncnt;
	if(L==R) { val[o]=a[L]; return; }
	int M=(L+R)>>1;
	build(lc[o],L,M); build(rc[o],M+1,R);
}
int modify(int o,int L,int R)
{
	int no=++ncnt;
	lc[no]=lc[o]; rc[no]=rc[o];
	if(L==R) { val[no]=nval; return no; }
	int M=(L+R)>>1;
	if(idx<=M) lc[no]=modify(lc[no],L,M);
	else rc[no]=modify(rc[no],M+1,R);
	return no;
}
int query(int o,int L,int R)
{
	if(L==R) return val[o];
	int M=(L+R)>>1;
	if(idx<=M) return query(lc[o],L,M);
	else return query(rc[o],M+1,R);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n,m);
	for(int i=1;i<=n;i++) read(a[i]);
	build(rt[0],1,n);
	for(int i=1;i<=m;i++)
	{
		read(v,opt);
		if(opt==1)
		{
			read(idx,nval);
			rt[i]=modify(rt[v],1,n);
		}
		else
		{
			read(idx);
			printf("%d\n",query(rt[v],1,n));
			rt[i]=rt[v];
		}
	}
	return 0;
}
/*
59
87
41
87
88
46
*/
