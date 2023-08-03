#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
struct Point{int x,y;Point(int _x=0,int _y=0){x=_x;y=_y;}};
struct Edge
{
	int f,t,dist;
	Edge(int F=0,int T=0,int D=0){f=F; t=T; dist=D;}
};
inline bool operator<(const Edge &a,const Edge &b)
{return a.dist<b.dist;}
struct Tc
{
	vector<int> vs;
	int cost;
};
const int oo=1<<30,maxn=1000;
int n,q,cnt,res;
int fa[maxn+5];
Point ps[maxn+5];
Edge e[maxn*maxn+5];
Tc ts[10];
vector<int> es;
inline int ff(int n)
{
	int a=n,b;
	while(n!=fa[n]) n=fa[n];
	while(a!=n)
	{
		b=fa[a];
		fa[a]=n;
		a=b;
	}
	return n;
}
int pro(int st)
{
	int res=0;
	for(int i=0;i<n;i++) fa[i]=i;
	for(int i=0;i<q;i++)
		if(st&(1<<i))
		{
			res+=ts[i].cost;
			for(int j=1;j<ts[i].vs.size();j++)
				if(ff(ts[i].vs[j])!=ff(ts[i].vs[j-1]))
					fa[ff(ts[i].vs[j])]=ff(ts[i].vs[j-1]);
		}
	for(int i=0;i<es.size();i++)
		if(ff(e[es[i]].f)!=ff(e[es[i]].t))
		{
			res+=e[es[i]].dist;
			fa[ff(e[es[i]].f)]=ff(e[es[i]].t);
		}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d",&n,&q);
		for(int i=0;i<q;i++)
		{
			ts[i].vs.clear();
			int x;
			scanf("%d",&x);
			ts[i].vs.resize(x);
			scanf("%d",&ts[i].cost);
			for(int j=0;j<x;j++)
			{
				scanf("%d",&ts[i].vs[j]);
				ts[i].vs[j]--;
			}
		}
		for(int i=0;i<n;i++) scanf("%d%d",&ps[i].x,&ps[i].y);
		cnt=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				e[cnt++]=Edge(i,j,(ps[i].x-ps[j].x)*(ps[i].x-ps[j].x)
				+(ps[i].y-ps[j].y)*(ps[i].y-ps[j].y));
		for(int i=0;i<n;i++) fa[i]=i;
		sort(e,e+cnt);
		res=oo;
		es.clear();
		for(int i=0;i<cnt;i++)
			if(ff(e[i].f)!=ff(e[i].t))
			{
				fa[ff(e[i].f)]=ff(e[i].t);
				es.push_back(i);
			}
		for(int i=0;i<(1<<q);i++) res=min(res,pro(i));
		printf("%d\n",res);
		if(T) printf("\n");
	}
	return 0;
}
