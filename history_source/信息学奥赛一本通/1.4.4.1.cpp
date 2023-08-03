#include<cstdio>
using namespace std;
int main()
{
	int n;
	long long ans=0,times=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		times*=i;
		ans+=times;
	}
	printf("%lld\n",ans);
	return 0;
}

