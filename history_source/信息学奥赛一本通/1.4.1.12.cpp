#include<cstdio>
using namespace std;
int main()
{
	double x;
	int n;
	scanf("%lf%d",&x,&n);
	for(int i=0;i<n;i++) x*=1.001;
	printf("%.4lf\n",x);
	return 0;
}

