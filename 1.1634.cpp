#include<cstdio>
typedef long long LL;
LL sum=1,x; int n;
int main()
{
	scanf("%lld%d",&x,&n);
	while(n-->0) sum=sum+sum*x;
	printf("%lld\n",sum);
	return 0;
}