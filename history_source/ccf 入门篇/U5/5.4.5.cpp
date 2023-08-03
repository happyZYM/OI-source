#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int n;
bool ish(string s)
{
	for(int i=0,j=s.size()-1;i<j;i++,j--) 
		if(s[i]!=s[j]) return 0;
	return 1;
}
char nums[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
int hash_(char n)
{
	if(n<='9') return n-'0';
	return n-'a'+10;
}
string plus_(string a,string b)
{
	int x,j=0;
	string ans;
	if(a.size()<b.size())
	{
		string c=a;
		a=b;
		b=c;
	}
	int ai=a.size()-1,bi=b.size()-1;
	for(;bi>=0;ai--,bi--)
	{
		x=hash_(a[ai])+hash_(b[bi])+j;
		ans=nums[x%n]+ans;
		j=x/n;
	}
	for(;ai>=0;ai--)
	{
		x=hash_(a[ai])+j;
		ans=nums[x%n]+ans;
		j=x/n;
	}
	if(j>0) ans="1"+ans;
	return ans;
}
string dao(string a)
{
	string ans;
	for(int i=a.size()-1;i>=0;i--) ans+=a[i];
	return ans;
}
int main()
{
	string s;
	cin>>n>>s;
	for(int i=0;i<=30;i++)
	{
		if(ish(s))
		{
			cout<<i<<endl;
			return 0;
		}
		if(i==30) break;
		s=plus_(s,dao(s));
	}
	cout<<"impossible"<<endl;
	return 0;
}
