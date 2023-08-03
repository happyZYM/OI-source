#include<cstdio>
#include<cmath>
int main()
{
	int n,tz,v,t,s=4.5*3600;
	while(scanf("%d",&n))
	{
		if(!n) return 0;
		int mint=10000;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&v,&t);
			if(t>=0)
			{
				tz=ceil((double)s/v)+t;
				if(tz<mint) mint=tz;
			}
		}
		printf("%d\n",mint);
	}
	return 0;
}
