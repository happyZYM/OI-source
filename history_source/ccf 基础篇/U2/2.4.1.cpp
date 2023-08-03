#include<iostream>
#include<string>
using namespace std;
bool pan(string sr)
{
	if(!((sr[0]>='a'&&sr[0]<='z')||(sr[0]>='A'&&sr[0]<='Z')||sr[0]=='_')) return 0;
	for(int i=0;i<sr.size();i++) if(!((sr[i]>='a'&&sr[i]<='z')||(sr[i]>='A'&&sr[i]<='Z')||sr[i]=='_'||(sr[i]>='0'&&sr[i]<='9'))) return 0;
	return 1;
}
int main()
{
	string sr;
	getline(cin,sr);
	if(pan(sr)) cout<<"yes";
	else cout<<"no";
	cout<<endl;
	return 0;
}
