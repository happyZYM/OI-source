#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	float a,b,c;
	while(true)
	{
		cin>>a>>b>>c;
		if(!((a+b>c)&&(a+c>b)&&(b+c>a))) cout<<"No!"<<endl;
		else
		{
			if(a==b&&a==c) cout<<"等边三角形"<<endl;
			else
			{
				if((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a)) cout<<"直角三角形"<<endl;
				else cout<<"一般三角形"<<endl;
			}
		}
	}
}
