#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005],n,T;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		int res=a[0]-a[1],MaxAi=a[0];
		for(int i=1;i<n;i++)
		{
			res=max(res,MaxAi-a[i]);
			MaxAi=max(MaxAi,a[i]);
		}
		printf("%d\n",res);
	}
	return 0;
}
