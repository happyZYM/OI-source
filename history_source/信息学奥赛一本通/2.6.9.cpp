#include<iostream>
#include<string>
using namespace std;
using std::string;
string a;
int k;
void operation()
{
	int j;
	for(int i=0;i<k;i++)
	{
		j=0;
		while(j<a.size()-1&&a[j]<=a[j+1]) j++;
		a.erase(a.begin()+j);
	}
	while(a.size()>1&&a[0]=='0') a.erase(a.begin());
}
int main()
{
	int t;
	cin>>t;
	string ans[t];
	for(int i=0;i<t;i++)
	{
		cin>>a>>k;
		operation();
		ans[i]=a;
	}
	for(int i=0;i<t;i++) cout<<ans[i]<<endl;
	return 0;
}
