#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int max,x;
	scanf("%d",&max);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&x);
		if(x>max) max=x;
	}
	printf("%d\n",max);
	return 0;
}

