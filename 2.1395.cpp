#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100;
struct Edge
{
	int a,b,v;
};
inline bool operator<(const Edge& a,const Edge& b)
{
	return a.v<b.v;
}
Edge e[maxn*maxn+5];
int fa[maxn+5];
const int oo=1<<30;
int ff(int n)
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
int n,m,res,L,R,cnt;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		for(int i=0;i<m;i++) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].v);
		sort(e,e+m);
		res=oo;
		for(L=0;L<m;L++)
		{
			for(int i=1;i<=n;i++) fa[i]=i;
			cnt=n;
			for(R=L;cnt>1&&R<m;R++)
				if(ff(e[R].a)!=ff(e[R].b))
				{
					fa[ff(e[R].b)]=ff(e[R].a);
					cnt--;
				}
			if(cnt==1) res=min(res,e[R-1].v-e[L].v);
		}
		printf("%d\n",res==oo?-1:res);
	}
	return 0;
}
