#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int L,n;
int a[55],d[55][55];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&L)==1&&L)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		a[n+1]=L;
		for(int i=1;i<=n+1;i++)
			for(int j=0;j+i<=n+1;j++)
			{
				if(i==1) d[j][j+1]=0;//a[j+1]-a[j];
				else
				{
					d[j][j+i]=1<<30;
					for(int k=j+1;k<j+i;k++)
						d[j][j+i]=min(d[j][j+i],d[j][k]+d[k][j+i]);
					d[j][j+i]+=a[j+i]-a[j];
				}
			}
		printf("The minimum cutting is %d.\n",d[0][n+1]);
	}
	return 0;
}
