#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float a,b,c,p;
	while(true){
		cin>>a>>b>>c;
		p=(a+b+c)/2.0;
		cout<<"S="<<sqrt(p*(p-a)*(p-b)*(p-c))<<endl;
	}
}
