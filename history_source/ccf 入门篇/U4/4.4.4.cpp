#include<iostream>
using namespace std;
int main()
{
	int n;
	while(true)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int a=1;a<=i;a++) cout<<a<<"*"<<i<<"="<<a*i<<"  ";
			cout<<endl;
		}
		cout<<endl;
	}
}
