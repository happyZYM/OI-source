#include<iostream>
#include<string> 
using namespace std;
int main()
{
	string a;
	while(true)
	{
		cin>>a;
		cout<<a<<"是"<<a.size()<<"位数"<<endl;
		for(int i=0;i<a.size();i++)
		{
			switch(i+1)
			{
				case 1:cout<<"个位 ";break;
				case 2:cout<<"十位 ";break;
				case 3:cout<<"百位 ";break;
				case 4:cout<<"千位 ";break;
			}
			cout<<a[a.size()-i-1]<<endl;
		}
		cout<<endl;
	}
}
