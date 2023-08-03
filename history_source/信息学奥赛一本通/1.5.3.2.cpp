#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int le[26]={0};
	for(int i=0;i<s.size();i++) le[s[i]-'a']++;
	for(int i=0;i<s.size();i++)
	{
		if(le[s[i]-'a']==1)
		{
			cout<<s[i]<<endl;
			return 0;
		}
	}
	cout<<"no"<<endl;
	return 0;
}

