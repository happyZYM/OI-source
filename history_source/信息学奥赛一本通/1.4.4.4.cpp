#include<iostream>
using namespace std;
bool is(int n)
{
	if(n%7==0) return 0;
	do
	{
		if(n%10==7) return 0;
		n/=10;
	}
	while(n);
	return 1; 
}
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(is(i)) ans+=i*i;
	cout<<ans<<endl;
	return 0;
}
