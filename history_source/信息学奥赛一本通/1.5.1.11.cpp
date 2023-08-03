#include<cstdio>
using namespace std;
int main()
{
	int n,max,min,x;
	scanf("%d",&n);
	scanf("%d",&x);
	max=min=x;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&x);
		if(x<min) min=x;
		if(x>max) max=x;
	} 
	printf("%d\n",max-min);
	return 0;
}

