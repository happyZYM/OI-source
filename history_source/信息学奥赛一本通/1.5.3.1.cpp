#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int ans=0;
	for(int i=0;i<s.size();i++) if(s[i]<='9'&&s[i]>='0') ans++;
	cout<<ans<<endl;
	return 0;
}

