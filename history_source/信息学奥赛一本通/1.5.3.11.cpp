#include<iostream>
#include<string> 
using namespace std;
void print(string n)
{
	if(n[0]>='a'&&n[0]<='z') n[0]-=32;
	for(int i=1;i<n.size();i++)
		if(n[i]>='A'&&n[i]<='Z') n[i]+=32;
	cout<<n<<endl;
}
int main()
{
	int n;
	cin>>n;
	string sr[n];
	for(int i=0;i<n;i++) cin>>sr[i];
	for(int i=0;i<n;i++) print(sr[i]);
	return 0;
}

