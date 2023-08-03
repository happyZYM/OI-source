#include<iostream>
#include<sstream>
using namespace std;
int main()
{
	string a;
	int l,r;
	stringstream li;
	cin>>l>>r;
	for(int i=l;i<=r;i++) li<<i;
	li>>a;
	int ans=0;
	for(int i=0;i<a.size();i++) if(a[i]=='2') ans++;
	cout<<ans<<endl;
	return 0;
}

