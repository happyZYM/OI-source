#include<iostream>
using namespace std;
bool isp(int n)
{
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
int main()
{
	long long n;
	cin>>n;
	for(int i=2;i*i<=n;i++)
	{
		if(isp(i)&&n%i==0)
		{
			cout<<n/i<<endl;
			return 0;
		}
	} 
	return 0;
}

