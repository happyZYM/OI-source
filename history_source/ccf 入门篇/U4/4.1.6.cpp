#include<iostream>
using namespace std;
int main()
{
	int n;
	int s;
	while(true)
	{
		cin>>n;
		s=0;
		for(int i=1;i*i<=n;i++)
		{
			if(n%i==0) s=s+2;
			if(i*i==n) s=s-1;
		}
		cout<<s<<endl;
	}
}
