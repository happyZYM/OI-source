#include<cstdio>
#include<cmath> 
using namespace std;
int main()
{
	float x;
	int n;
	scanf("%f%d",&x,&n);
	float ans=0,times=1;
	for(int i=0;i<=n;i++)
	{
		ans+=times;
		times*=x;
	}
	printf("%f\n",ans);
	return 0;
}

