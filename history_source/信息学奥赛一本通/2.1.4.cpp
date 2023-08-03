#include<iostream>
#include<string>
using namespace std;
void swap(string &a,string &b)
{
	string c;
	c=a;
	a=b;
	b=c;
}
void eraseZero(string &a)
{
	while(a[0]=='0'&&a.size()>1) a.erase(0,1);
}
bool can(string a,int b)
{
	int yu=0;
	for(int i=0;i<a.size();i++)
		yu=(yu*10+a[i]-'0')%b;
	if(yu==0) return 1;
	return 0;
}
int main()
{
	string a;
	cin>>a;
	bool f=1;
	for(int i=2;i<=9;i++)
	{
		if(can(a,i))
		{
			f=0;
			cout<<i<<" ";
		} 
	}
	if(f) cout<<"none";
	cout<<endl;
	return 0;
}
