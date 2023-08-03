#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double l=200,s=0;
	do
	{
		s=s+l;
		l/=2;
	} while(l>=0.5);
	cout<<s;
	while(true);
}
