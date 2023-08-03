#include<iostream>
#include<vector>
using namespace std;
long long zk(int sr)
{
	if(sr==2) return 2;
	if(sr==1) return 1;
	return zk(sr-1)*2+zk(sr-2);
}
int main()
{
	vector <int> sr;
	int n;
	while(true)
	{
		cin>>n;
		sr.resize(n);
		for(int i=0;i<n;i++) cin>>sr[i];
		for(int i=0;i<n;i++) cout<<zk(sr[i])<<endl;
	}
}
