#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	cin.tie(0);
	int n;
	while(cin>>n&&n)
	{
		long long ans=0,a,last=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			ans+=abs(last);
			last+=a;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
