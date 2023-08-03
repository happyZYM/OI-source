#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double three=sqrt(3),add=0,x;
	for(int i=1;i>0;i++)
	{
		x=(1.0/pow(three,i*2-1))/(double)(i*2-1);
		if(x<0.000001) break;
		if(i&1) add+=x;
		else add-=x;
	} 
	printf("%g\n",6*add);
	return 0;
}
