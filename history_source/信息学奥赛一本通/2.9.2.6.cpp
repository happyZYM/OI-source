#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int sum,maxn,i,j,f[20001],a;
int main()
{
	scanf("%d%d",&maxn,&sum);
	for(i=1;i<=sum;i++)
	{
		scanf("%d",&a);
		for(j=maxn;j>=a;j--)
			f[j]=max(f[j],f[j-a]+a);
	}
	printf("%d\n",maxn-f[maxn]);
	return 0;
}
