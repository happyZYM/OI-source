#include<iostream>
using namespace std;
int main()
{
	while(true)
	{
		
	int n,b,s,a;
	cin>>n;
	cin>>s;
	b=s+1;
	for(int i=0;i<n-1;i++)
	{
		cin>>a;
		if(a>b) b=a;
		else if(a<s) s=a;
	}
	cout<<b-s<<endl<<endl;
    }
}
