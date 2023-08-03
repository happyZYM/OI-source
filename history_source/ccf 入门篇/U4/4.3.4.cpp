#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
int main()
{
	stringstream num;
	string j;
	int a,b;
	bool z,x;
	while(true)
	{
		cin>>a;
		z=0;
		if(a<0){z=1;a=abs(a);}
		b=0;
		do
		{
			b=b*10+a%10;
			a/=10;
		}while(a>0);
		a=b;
		if(z==1) a=0-a;
		cout<<a<<endl;
	}
}
