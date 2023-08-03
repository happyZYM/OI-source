#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int max,x,min;
	scanf("%d",&max);
	min=max;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&x);
		if(x>max) max=x;
		if(x<min) min=x;
	}
	printf("%d\n",max-min);
	return 0;
}
