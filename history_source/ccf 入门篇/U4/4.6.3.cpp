#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,a,b;
	while(true)
	{
		cin>>n;
		for(int i=2;i*i<n;i++)
		{
			if(n%i==0)
			{
				a=i;
				b=n/a;
				break;
			}
		}
		cout<<((a>b)?a:b)<<endl;
	}
}
