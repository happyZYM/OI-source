#include<cstdio>
int T,n,m;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",(n-(n/m+(n%m!=0)))%2==0?1:0);
	}
	return 0;
}
