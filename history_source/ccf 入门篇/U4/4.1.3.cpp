#include<iostream>
using namespace std;
int main()
{
	float n,s,p;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p;
		s=s+p;
	}
	p=s/n;
	cout<<int(p*100.0)/100.0;
	while(true);
}
