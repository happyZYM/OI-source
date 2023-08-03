#include<cstdio>
int main()
{
	double max=0,sum=0,t;
	int n,i;
	while(scanf("%d",&n)==1)
	{
		max=sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&t);
			sum+=t;
			if(t>max) max=t;
		}
		if(sum-max<max) printf("%.1lf\n",sum-max);
		else printf("%.1lf\n",sum/2.0);
	}
	return 0;
}
