#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1299709;
bool vis[maxn+5]={1,1};
int pri[100005],cnt,n;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int m=(int)sqrt(maxn+0.5),c=0,i,j;
	for(i=2;i<=m;i++)
		if(!vis[i])
			for(j=i*i;j<=maxn;j+=i) vis[j]=1;
	for(i=2;i<=maxn;i++)
		if(!vis[i]) pri[cnt++]=i;
	while(scanf("%d",&n)==1&&n)
	{
		if(!vis[n]) printf("0\n");
		else
		{
			int *p=upper_bound(pri,pri+cnt,n);
			printf("%d\n",*p-*(p-1));
		}
	}
	return 0;
}
