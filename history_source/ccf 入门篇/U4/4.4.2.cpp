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
			for(int a=0;a<i*2+1;a++) cout<<"*";
			for(int a=0;a<(n*2-1-i*2-1)/2;a++) cout<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
}
