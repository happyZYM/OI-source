#include<cstdio>
#include<algorithm>
using namespace std;
struct { int l,r,ans; } query[10010];
int n,m,fa[20010],d[20010],a[20010],cnt;
inline int ff(int u)
{
	int a=u,b,c=0;
	while(u!=fa[u]) c^=d[u],u=fa[u];
	while(a!=u)
	{
		b=fa[a];
		c^=d[a];
		d[a]^=c;
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		char s[10]; scanf("%d%d%s",&query[i].l,&query[i].r,s);
		query[i].ans=(s[0]=='o');
		a[++cnt]=query[i].l-1; a[++cnt]=query[i].r;
	}
	sort(a+1,a+1+cnt); n=unique(a+1,a+1+cnt)-(a+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=lower_bound(a+1,a+1+n,query[i].l-1)-a;
		int y=lower_bound(a+1,a+1+n,query[i].r)-a;
		int p=ff(x),q=ff(y);
		if(p==q)
		{
			if((d[x]^d[y])!=query[i].ans)
			{
				printf("%d\n",i-1);
				return 0;
			}
		}
		else
		{
			fa[p]=q;
			d[p]=d[x]^d[y]^query[i].ans;
		}
	}
	printf("%d\n",m);
	return 0;
}
