#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(true)
	{
		cin>>a;
		do
		{
			b=0;
			do
			{
				b=b+a%10;
				a/=10;
			}
			while(a>0);
			a=b;
		}
		while(a/10>0);
		cout<<a;
	}
}
