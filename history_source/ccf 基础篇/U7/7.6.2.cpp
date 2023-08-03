#include<cstdio>
#include<algorithm>
using namespace std;
int num[100010];
int main()
{
	freopen("data.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",num+i);
	int max,maxn;
	max=maxn=num[0];
	for(int i=1;i<n;i++)
	{
		if(maxn<0) maxn=num[i];
		else maxn+=num[i];
		if(maxn>max) max=maxn;
	}
	printf("%d\n",max);
	return 0;
}
