#include<iostream>
using namespace std;
int main()
{
	int a;
	while(true)
	{
		cout<<"[1]apples"<<endl<<"[2]pears"<<endl<<"[3]oranges"<<endl<<"[4]grapes"<<endl<<"[0]Exit"<<endl;
		cin>>a;
		cout<<"price= ";
		switch(a)
		{
			case 1:cout<<3.0;break;
			case 2:cout<<2.5;break;
			case 3:cout<<4.2;break;
			case 4:cout<<10.2;break;
			case 0:return 0;
			default:cout<<0;
		}
		cout<<endl<<endl;
	}
} 
