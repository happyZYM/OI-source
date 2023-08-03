#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100,oo=1<<30;
int d[maxn+5][maxn+5];
int n,m,q,a,b,c,i,j,k,kase;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d%d",&n,&m,&q)==3&&!(n==0&&m==0&&q==0))
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				d[i][j]=(i==j?0:oo);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			d[a][b]=d[b][a]=c;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
		if(kase) printf("\n");
		printf("Case #%d\n",++kase);
		for(i=0;i<q;i++)
		{
			scanf("%d%d",&a,&b);
			if(d[a][b]==oo) printf("no path\n");
			else printf("%d\n",d[a][b]);
		}
	}
	return 0;
}
