#include<iostream>
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
	printf("%.0lf\n",add);
	add=add/n;
	cout<<add<<endl;
	return 0;
}

