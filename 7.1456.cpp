#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10005;
struct DT { int p,d; };
inline bool operator<(const DT &a,const DT &b) { return a.p>b.p; }
int n,fa[maxn]; DT a[maxn];
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
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i].p,&a[i].d);
		for(int i=0;i<=10000;i++) fa[i]=i;
		sort(a+1,a+1+n);
		int res=0;
		for(int i=1;i<=n;i++)
		{
			int r=ff(a[i].d);
			if(r>0)
			{
				res+=a[i].p;
				fa[r]=r-1;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
/*
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=10005;
struct OBJ { int p,d; };
int n; OBJ a[maxn];
inline bool operator<(const OBJ &a,const OBJ &b) { return a.d<b.d; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++) scanf("%d %d",&a[i].p,&a[i].d);
		sort(a,a+n);
		priority_queue<int,vector<int>,greater<int> > Q;
		Q.push(a[0].p);
		for(int i=1;i<n;i++)
		{
			if(a[i].d==Q.size()&&a[i].p>Q.top()) { Q.pop(); Q.push(a[i].p); }
			else if(a[i].d>Q.size()) Q.push(a[i].p);
		}
		int res=0;
		while(Q.size()) { res+=Q.top(); Q.pop(); }
		printf("%d\n",res);
	}
	return 0;
}
*/
