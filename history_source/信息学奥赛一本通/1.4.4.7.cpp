#include<iostream>
using namespace std;
int main()
{
	int x,y;
	bool s;
	char c;
	cin>>y>>x>>c>>s;
	for(int i=0;i<x;i++) cout<<c;
	cout<<endl;
	for(int i=1;i<y-1;i++)
	{
		cout<<c;
		if(s) for(int i=1;i<x-1;i++) cout<<c;
		else for(int i=1;i<x-1;i++) cout<<' ';
		cout<<c;
		cout<<endl;
	}
	for(int i=0;i<x;i++) cout<<c;
	cout<<endl;
	return 0;
}

