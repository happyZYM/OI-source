#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=30005;
int M,fa[maxn],d[maxn],sz[maxn];
inline int ff(int u)
{
	int a=u,b,c=0;
	while(u!=fa[u]) c+=d[u],u=fa[u];
	while(a!=u)
	{
		b=fa[a];
		c-=d[a];
		d[a]+=c;
		fa[a]=u;
		a=b;
	}
	return u;
}
inline void merge(int x,int y)
{
	x=ff(x); y=ff(y);
	fa[x]=y; d[x]=sz[y]; sz[y]+=sz[x];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&M);
	for(int i=1;i<=30000;i++) fa[i]=i,sz[i]=1;
	while(M-->0)
	{
		char op; int x,y; scanf("%s %d %d",&op,&x,&y);
		if(op=='M') merge(x,y);
		else
		{
			if(ff(x)!=ff(y)) puts("-1");
			else printf("%d\n",abs(d[x]-d[y])-1);
		}
	}
	return 0;
}
