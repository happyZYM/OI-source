#include<cstdio>
using namespace std;
int main()
{
	int n,max=-100000000;
	unsigned long long ans=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		if(a[i]>max) max=a[i];
	}
	for(int i=0;i<n;i++) if(a[i]<max) ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}

