#include<cstdio>
using namespace std;
int main()
{
	double s;
	scanf("%lf",&s);
	if(s==100) printf("All\n");
	if(s>100) printf("Bike\n");
	if(s<100) printf("Walk\n");
	return 0;
}

