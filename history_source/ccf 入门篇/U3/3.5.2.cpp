#include<iostream>
using namespace std;
int main()
{
	long double a;
	while(true)
	{
		cin>>a;
		if(a>=0&&a<5) cout<<a+2.5<<endl;
		else
		{
			if(a>=5&&a<10) cout<<2-1.5*(a-3)*(a-3)<<endl;
			else
			{
				if(a>=10&&a<20) cout<<a/2-1.5<<endl;
				else cout<<"ÊäÈëÎÞÐ§!"<<endl;
			}
		}
	}
}
