#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=505;
const int maxm=2005;
int n,m,x[maxm],d[maxm],y[maxm],fa[maxn*3];
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
	fa[x]=y;
}
int check(int id)
{
	for(int i=1;i<=n*3;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(x[i]==id||y[i]==id) continue;
		int Xself=x[i]*3,Xeat=x[i]*3-1,Xenemy=x[i]*3-2;
		int Yself=y[i]*3,Yeat=y[i]*3-1,Yenemy=y[i]*3-2;
		if(d[i]==0)
		{
			if(ff(Xeat)==ff(Yself)) return i;
			if(ff(Xself)==ff(Yeat)) return i;
			merge(Xeat,Yeat);
			merge(Xself,Yself);
			merge(Xenemy,Yenemy);
		}
		else
		{
			if(ff(Xself)==ff(Yself)) return i;
			if(ff(Xself)==ff(Yeat)) return i;
			merge(Xeat,Yself);
			merge(Xself,Yenemy);
			merge(Xenemy,Yeat);
		}
	}
	return 0;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=1;i<=m;i++)
		{
			char op; scanf("%d%c%d",&x[i],&op,&y[i]);
			x[i]++; y[i]++;
			d[i]=(op=='>'?1:(op=='='?0:-1));
			if(d[i]==-1) d[i]=1,swap(x[i],y[i]);
		}
		// for(int i=1;i<=m;i++) printf("%d %d %d\n",x[i],d[i],y[i]);
		// puts("");
		int rd=0,tot=0,id=0;
		for(int i=1;i<=n;i++)
		{
			int v=check(i);
			rd=max(rd,v);
			if(v==0) tot++,id=i;
		}
		if(tot==0) puts("Impossible");
		else if(tot>1) puts("Can not determine");
		else printf("Player %d can be determined to be the judge after %d lines\n",id-1,rd);
	}
	return 0;
}