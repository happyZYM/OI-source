#include<iostream>
#include<cmath>
using namespace std;
bool pan(int a)
{
	do
	{
		if(a%10==0) return 0;
		a/=10;
	}
	while(a>0);
	return 1;
}
int main()
{
	int x=sqrt(111111111)+1,a;
	for(;x*x<=999999999;x++)
	{
		a=x*x; 
		if(pan(a)) cout<<x<<"^2="<<a<<endl;
	}
    while(true); 
}
