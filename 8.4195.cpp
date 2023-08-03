#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1000005;
int T,n,x[maxn],y[maxn],z[maxn],a[maxn*2],cnt,fa[maxn*2];
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
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
		cnt=0;
		for(int i=1;i<=n;i++) a[++cnt]=x[i],a[++cnt]=y[i];
		sort(a+1,a+1+cnt);
		cnt=unique(a+1,a+1+cnt)-(a+1);
		for(int i=1;i<=n;i++)
		{
			x[i]=lower_bound(a+1,a+1+cnt,x[i])-a;
			y[i]=lower_bound(a+1,a+1+cnt,y[i])-a;
		}
		for(int i=1;i<=cnt;i++) fa[i]=i;
		int flg=1;
		for(int i=1;i<=n;i++) if(z[i]==1)
		{
			int a=ff(x[i]),b=ff(y[i]);
			if(a!=b) fa[a]=b;
		}
		for(int i=1;i<=n;i++) if(z[i]==0)
			if(ff(x[i])==ff(y[i])) { flg=0; break; }
		puts(flg?"YES":"NO");
	}
	return 0;
}
