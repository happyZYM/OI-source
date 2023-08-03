#include<cstdio>
using namespace std;
int main()
{
	double prise[10]={28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
	double ans=0;
	int x;
	for(int i=0;i<10;i++)
	{
		scanf("%d",&x);
		ans+=prise[i]*x;
	}
	printf("%.1lf\n",ans);
	return 0;
}

