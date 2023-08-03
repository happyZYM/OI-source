#include<iostream>
#include<cmath> 
using namespace std;
int main()
{
	long long a,b;
	while(true)
	{
		cin>>a>>b;
		a=a%10; 
		for(int i=1;i<b;i++){
			a=a*a;
			a=a%10;
		}
		cout<<a<<endl;
	}
}
