#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,a,b,x;
	getline(cin,s);
	cin>>a>>b;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=' ') x+=s[i];
		else
		{
			if(x==a) cout<<b<<" ";
			else cout<<x<<" ";
			x="";
		}
	}
	if(x==a) cout<<b<<" ";
	else cout<<x<<" ";
	return 0;
}

