#include<cstdio>
using namespace std;
int main()
{
	int n;
	double a,b,c,ans=0;
	a=b=c=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		c=a+b;
		ans+=c/b;
		a=b;
		b=c;
	}
	printf("%.4lf\n",ans);
	return 0;
}

