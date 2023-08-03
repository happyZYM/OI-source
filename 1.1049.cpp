#include<cstdio>
#include<algorithm>
using namespace std;
int n,v,w;
int f[20005];
int main()
{
	scanf("%d%d",&v,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&w);
		for(int j=v;j>=w;j--) f[j]=max(f[j-w]+w,f[j]);
	}
	printf("%d\n",v-f[v]);
	return 0;
}
