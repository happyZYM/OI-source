#include<cstdio>
using namespace std;
int main()
{
	int n;
	double ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(i&1) ans+=1.0/i;
		else ans-=1.0/i;
	}
	printf("%.4lf\n",ans);
	return 0;
}

