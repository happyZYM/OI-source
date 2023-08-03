#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 900
int i,j,cases,n,m,tot,t;
int a[maxn];
double sum,high,per;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0&&m==0) return 0;
		for(i=1;i<=n*m;i++)
			scanf("%d",&a[i]);
		scanf("%lf",&sum);
		sum/=100;
		sort(a+1,a+n*m+1);
		for(i=2;i<=n*m;i++)
		{
			tot=(a[i]-a[i-1])*(i-1);
			if(sum>=tot)
			{
				sum-=tot;
			}
			else
			{
				high=a[i-1]+sum/(i-1);
				sum=0;
				per=(double)(i-1)/n/m;
				break;
			}
		}
		if(sum)//ÑÍÃ»Õû¸öµØÇøÈÔÓÐÊ£Óà
		{
			high=a[n*m]+sum/n/m;
			per=1;
		}
		printf("Region %d\n",++cases);
		printf("Water level is %.2lf meters.\n",high);
		printf("%.2lf percent of the region is under water.\n\n",per*100);
	}
	return 0;
}
