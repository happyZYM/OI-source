#include<iostream>
using namespace std;
int main()
{
	int n;
	while(true)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int a=0;a<(n*2-1-i*2-1)/2;a++) cout<<" ";
			for(int a=1;a<=i*2+1;a++) cout<<a;
			for(int a=0;a<(n*2-1-i*2-1)/2;a++) cout<<" ";
			cout<<endl;
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int a=0;a<i;a++) cout<<" ";
			for(int a=1;a<=2*n-1-2*i;a++) cout<<a;
			for(int a=0;a<i;a++) cout<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
}
