#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=20005;
const int maxm=100005;
struct ZF { int a,b,c; };
inline bool operator<(const ZF &x,const ZF &y) { return x.c>y.c; }
int n,m,fa[maxn*2];
ZF zf[maxm];
inline int ff(int u)
{
	int a=u,b;
	while(u!=fa[u]) u=fa[u];
	while(a!=u)
	{
		b=fa[a];
		fa[a]=u;
		a=b;
	}
	return u;
}
inline void merge(int a,int b)
{
	a=ff(a); b=ff(b);
	fa[a]=b;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&zf[i].a,&zf[i].b,&zf[i].c);
	sort(zf+1,zf+m+1);
	for(int i=1;i<=n*2;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int ax=zf[i].a*2,ay=zf[i].a*2-1;
		int bx=zf[i].b*2,by=zf[i].b*2-1;
		merge(ax,by);
		merge(ay,bx);
		if(ff(ax)==ff(ay)||ff(bx)==ff(by)) { printf("%d\n",zf[i].c); return 0; }
	}
	puts("0");
	return 0;
}