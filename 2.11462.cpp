#include<cstdio>
#include<cstring>
int n,x,c[101];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		memset(c,0,sizeof(c));
		while(n-->0)
		{
			scanf("%d",&x);
			++c[x];
		}
		n=0;
		for(x=1;x<=100;x++)
			while(c[x]-->0)
			{
				if(n) printf(" ");
				n=1;
				printf("%d",x);
			}
		printf("\n");
	}
	return 0;
}
