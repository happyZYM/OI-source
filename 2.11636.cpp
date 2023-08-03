#include<cstdio>
#include<cmath>
int n,kase;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n>0)
		printf("Case %d: %d\n",++kase,(int)ceil(log2(n)));
	return 0;
}
