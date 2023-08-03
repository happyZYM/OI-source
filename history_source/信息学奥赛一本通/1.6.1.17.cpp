#include<iostream>
#include<string>
using namespace std;
long long turn(string num,int j)
{
	long long ans=0;
	int i=0;
	if(num[0]=='-') i++;
	for(;i<num.size();i++) ans=ans*j+num[i]-'0';
	if(num[0]=='-') ans=-ans;
	return ans;
}
bool can(string num,int j)
{
	int i=0;
	if(num[0]=='-') i++;
	for(;i<num.size();i++) if(num[i]-'0'>=j) return 0;
	return 1;
}
int main()
{
	string a,b,c;
	cin>>a>>b>>c;
	for(int i=2;i<=16;i++)
	{
		if(can(a,i)&&can(b,i)&&can(c,i)&&turn(a,i)*turn(b,i)==turn(c,i))
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}

