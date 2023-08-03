#include<iostream>
using namespace std;
int main()
{
	int n;
	while(true)
	{
		cin>>n;
		do
		{
			cout<<"ÉÌ "<<n/2<<"£¬"<<"Óà "<<n%2<<endl;
			n/=2;
		}
		while(n>0);
		cout<<endl;
	}
}
