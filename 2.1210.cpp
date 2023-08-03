#include<cstdio>
inline bool isp(int a)
{
	for(int i=2;i*i<=a;i++)
		if(a%i==0) return false;
	return true;
}
int p[10000],cnt,n,res,head,tail,sum;
int main()
{
	for(int i=2;i<=10000;i++)
		if(isp(i)) p[cnt++]=i;
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		res=(p[0]==n);
		head=0;tail=1;
		sum=p[0];
		while(tail<cnt&&head<cnt)
		{
			sum+=p[tail++];
			while(sum>n) sum-=p[head++];
			if(sum==n) res++;
		}
		printf("%d\n",res);
	}
	return 0;
}
