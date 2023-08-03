#include<iostream>
#include<string>
using namespace std;
void print(string a,string b)
{
	cout<<a<<" is substring of "<<b<<endl;
}
int main()
{
	string a,b;
	cin>>a>>b;
	if(a==b){
		print(a,b);
		return 0;
	}
	for(int i=0;i+a.size()<=b.size();i++)
	{
		if(b.substr(i,a.size())==a)
		{
			print(a,b);
			return 0;
		}
	}
	for(int i=0;i+b.size()<=a.size();i++)
	{
		if(a.substr(i,b.size())==b)
		{
			print(b,a);
			return 0;
		}
	}
	cout<<"No substring"<<endl;
	return 0;
}

