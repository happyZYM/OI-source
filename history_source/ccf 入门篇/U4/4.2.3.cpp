#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int m,n,b,i;
	while(true)
	{
		cin>>m>>n;
		b=(m>n)?m:n;
		for(i=2;i<=b;i++)
		{
			if(m%i==0&&n%i==0) {cout<<"No"<<endl;break;}
		}
		if(!(m%i==0&&n%i==0)) cout<<"Yes"<<endl;
	}
}
