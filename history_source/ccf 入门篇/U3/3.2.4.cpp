#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	int a;
	while(true)
	{
		cin>>a;
		if((a%123>=97)&&(a%123<=122)) cout<<char(a%123)<<endl;
		else
		{
		if((a%91>=65)&&(a%91<=90))	cout<<char(a%91)<<endl;
		else
		{
			cout<<"*"<<endl;
		} 
		} 
	}
}
