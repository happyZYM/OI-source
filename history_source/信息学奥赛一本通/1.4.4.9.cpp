#include<iostream>
using namespace std;
bool isp(int n)
{
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
int main()
{
	int n;
	long long p;
	cin>>n;
	for(long long i=2,j=0;j<n;i++)
	{
		if(isp(i))
		{
			p=i;
			j++;
		}
	}
	cout<<p<<endl;
	return 0;
}

