#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long ans=0;
	int i;
	for(i=1;n-i>=0;i++)
	{
		ans+=i*i;
		n-=i;
	}
	if(n>0) ans+=n*i;
	cout<<ans<<endl; 
	return 0;
}

