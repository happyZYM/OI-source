#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	char a;
	string x;
	stringstream b;
		b.flush();
		cin>>x;
		for(int i=0;i<x.size();i++){
			a=x[i];
			a=97+(a-97+17)%24;
			b<<a;
		}
		x="";
		b>>x;
		cout<<x<<endl;
	while(1==1);
}
