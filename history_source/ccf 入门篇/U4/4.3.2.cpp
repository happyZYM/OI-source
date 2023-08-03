#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long double pi4=0;
	long long n=1,j=1;
	do
	{
		if(j%2==1) pi4=pi4+1.0/n;
		else pi4=pi4-1.0/n;
		n+=2;
		j++;
	}while(1.0/n>=0.000001);
	cout<<pi4*4.0;
	while(true);
}
