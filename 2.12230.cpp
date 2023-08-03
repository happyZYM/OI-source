#include<cstdio>
int n,D,p,L,v,kase;
double res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&D)==2&&D)
	{
		res=0;
		while(n--)
		{
			scanf("%d%d%d",&p,&L,&v);
			D-=L;
			res+=2.0*L/v;
		}
		printf("Case %d: %.3lf\n\n",++kase,res+D);
	}
	return 0;
}
