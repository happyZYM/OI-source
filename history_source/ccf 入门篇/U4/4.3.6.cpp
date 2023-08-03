#include<iostream>
using namespace std;
int main()
{
	int n,a;
	while(true)
	{
		cin>>n;
		a=1;
		while(n!=1)
		{
			if(n%2==0) n/=2;
			else n=3*n+1;
			a++;
		} 
		cout<<a<<endl;
	}
}
