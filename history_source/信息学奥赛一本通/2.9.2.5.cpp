#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int sum,maxn,i,j,f[12881],a,b;
int main()
{
	scanf("%d%d",&sum,&maxn);
	for(i=1;i<=sum;i++)
	{
		scanf("%d%d",&a,&b);
		for(j=maxn;j>=a;j--)
			f[j]=max(f[j],f[j-a]+b);
	}
	printf("%d\n",f[maxn]);
	return 0;
}
