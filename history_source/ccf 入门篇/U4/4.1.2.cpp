#include<iostream>
using namespace std;
int main()
{
	long double s=1;
	for(int i=2;i<=100;i++)
	{
		if(i%2==1) s=s-i;
		else s=s+i;
	}
	cout<<int(s)<<endl;
	s=0;
	for(int i=1;i<=10;i++)
	{
		s=s+i*(11-i);
	}
	cout<<int(s)<<endl;
	s=0;
	for(int i=1;i<=100;i++)
	{
		s=s+1.0/i;
	}
	cout<<s;
	while(true);
}
