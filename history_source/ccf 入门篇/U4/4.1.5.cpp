#include<iostream>
using namespace std;
int main()
{
	unsigned long long s;
	s=1;
	for(int i=1;i<64;i++)
	{
		s=s+s*2;
	}
	long double t;
	t=s/142000000;
	cout<<t;
	while(true);
}
