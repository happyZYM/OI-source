#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	double add,x;
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&x);
		add+=x;
	}
	add=add/n;
	printf("%lf",add);
	return 0;
}

