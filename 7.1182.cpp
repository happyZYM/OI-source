#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50005;
int n,m,fa[maxn*3];
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
inline void merge(int x,int y)
{
	x=ff(x); y=ff(y);
	if(x!=y) fa[x]=y;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	int res=0;
	for(int i=3;i<=n*3+2;i++) fa[i]=i;
	while(m-->0)
	{
		int d,x,y; scanf("%d%d%d",&d,&x,&y);
		int Xself=x*3,Xeat=x*3+1,Xenemy=x*3+2;
		int Yself=y*3,Yeat=y*3+1,Yenemy=y*3+2;
		if(x>n||y>n||(d==2&&x==y)) { res++; goto nxt; }
		if(d==1)
		{
			if(ff(Xeat)==ff(Yself)) { res++; goto nxt; }
			if(ff(Yeat)==ff(Xself)) { res++; goto nxt; }
			merge(Xeat,Yeat); merge(Xself,Yself); merge(Xenemy,Yenemy);
		}
		else
		{
			if(ff(Xself)==ff(Yself)) { res++; goto nxt; }
			if(ff(Xself)==ff(Yeat)) { res++; goto nxt; }
			merge(Xeat,Yself); merge(Xself,Yenemy); merge(Xenemy,Yeat);
		}
		nxt:;
	}
	printf("%d\n",res);
	return 0;
}
