#include<cstdio>
using namespace std;
int main()
{
	double h,add=0,high;
	scanf("%lf",&h);
	for(int i=0;i<10;i++)
	{
		add+=h;
		h/=2;
		add+=h;
	}
	add-=h;
	printf("%g\n%g\n",add,h);
	return 0;
}
