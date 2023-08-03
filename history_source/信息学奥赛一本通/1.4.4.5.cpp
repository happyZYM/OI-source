#include<iostream>
#include<sstream>
using namespace std;
int main()
{
	string a;
	int n;
	stringstream li;
	cin>>n;
	for(int i=1;i<=n;i++) li<<i;
	li>>a;
	int ans=0;
	for(int i=0;i<a.size();i++) if(a[i]=='1') ans++;
	cout<<ans<<endl;
	return 0;
}

