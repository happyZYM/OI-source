#include<cstdio>
using namespace std;
int main()
{
	int n;
	long long times=1;
	double ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		times*=i;
		ans+=1.0/times;
	}
	printf("%.10lf\n",ans+1);
	return 0;
}

