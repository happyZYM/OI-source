#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10005;
int T,n,m,u[maxn],v[maxn],id[maxn],vis[maxn],fa[maxn*2];
bool cr(int x1, int x2, int y1, int y2)
{
    if(x1==x2||y1==y2||x1==y2||x2==y1) return 0;
    return (x1<x2&&y1<y2&&x2<y1)||(x2<x1&&y2<y1&&x1<y2);
}
inline int ff(int x)
{
	int a=x,b;
	while(x!=fa[x]) x=fa[x];
	while(a!=x)
	{
		b=fa[a];
		fa[a]=x;
		a=b;
	}
	return x;
}
inline void merge(int x,int y)
{
	x=ff(x); y=ff(y);
	if(x!=y) fa[y]=x;
}
int main()
{
#ifdef local
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
		for(int i=1;i<=n;i++)
		{
			int x; scanf("%d",&x);
			id[x]=i;
		}
		if(m>3*n-6) { puts("NO"); continue; }
		for(int i=1;i<=m;i++)
		{
			int x=id[u[i]],y=id[v[i]];
			if(x>y) swap(x,y);
			u[i]=x; v[i]=y;
		}
		for(int i=1;i<=m;i++) vis[i]=(u[i]%n+1==v[i]);
		for(int i=1;i<=m*2;i++) fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			if(vis[i]) continue;
			for(int j=1;j<=m;j++)
			{
				if(vis[j]) continue;
				if(!cr(u[i],u[j],v[i],v[j])) continue;
				if(ff(i)==ff(j))
				{
					puts("NO");
					goto nxt;
				}
				merge(i,j+m);
				merge(j,i+m);
			}
		}
		puts("YES");
		nxt:;
	}
	return 0;
}
