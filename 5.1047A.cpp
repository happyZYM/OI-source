#include<cstdio>
#include<cstdlib>
int n;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int a,b,c;
	scanf("%d",&n);
	while(true)
	{
		a=rand()%(n-2)+1;
		b=rand()%(n-a-1)+1;
		c=n-a-b;
		if(a%3&&b%3&&c%3)
		{
			printf("%d %d %d\n",a,b,c);
			return 0;
		}
	}
	return 0;
}
