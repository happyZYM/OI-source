#include<iostream>
#include<string>
using namespace std;
int main()
{
	string password,sr;
	char sr2;
	password="NOIP@CCF";
	while(true)
	{
		cout<<">>> ";
		cin>>sr2;
		if(sr2=='N') break;
		else
		{
			cin>>sr;
			if(sr==password) {cout<<"Succrss";break;}
			else cout<<"Sorry"<<endl;
		}
	}
	if(sr==password) while(true);
}
