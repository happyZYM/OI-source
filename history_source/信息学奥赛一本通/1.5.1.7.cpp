#include<cstdio>
using namespace std;
int main()
{
	int n;
	unsigned long long ans=0;
	scanf("%d",&n);
	int w[n],x;
	for(int i=0;i<n;i++) scanf("%d",w+i);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		ans+=x*w[i];
	}
	printf("%lld\n",ans);
	return 0;
}

