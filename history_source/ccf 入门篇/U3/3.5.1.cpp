#include<iostream>
using namespace std;
int main()
{
	long double x;
	while(true)
	{
		cin>>x;
		if(x=0.5) cout<<"0.5 min"<<endl;
		else cout<<(x-0.5)/0.2+3<<" min"<<endl;
	}
}
