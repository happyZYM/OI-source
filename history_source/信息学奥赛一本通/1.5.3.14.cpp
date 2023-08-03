#include<iostream>
#include<string> 
using namespace std;
int main()
{
	string a;
	getline(cin,a);
	bool flag=0;
	int add=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=' ') add++;
		else if(add>0)
		{
			if(flag) cout<<",";
			cout<<add;
			flag=1;
			add=0;
		}
	}
	if(flag) cout<<",";
	cout<<add;
	return 0;
}

