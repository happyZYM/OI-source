#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=20010;
int pa[maxn],d[maxn];
int ff(int x)
{
	if(pa[x]!=x)
	{
		int root=ff(pa[x]);
		d[x]+=d[pa[x]];
		return pa[x]=root;
	}
	else return x;
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
		int n,u,v;
		char cmd[10];
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			pa[i]=i;
			d[i]=0;
		}
		while(scanf("%s",cmd)==1&&cmd[0]!='O')
		{
			if(cmd[0]=='E')
			{
				scanf("%d",&u);
				ff(u);
				printf("%d\n",d[u]);
			}
			if(cmd[0]=='I')
			{
				scanf("%d%d",&u,&v);
				pa[u]=v;
				d[u]=abs(u-v)%1000;
			}
		}
	}
	return 0;
}
