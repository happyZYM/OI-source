#include<iostream>
using namespace std;
int main()
{
	int x,a,y,b;
	cin>>x>>a>>y>>b;
	int d=(b*y-x*a)/(b-a);
	cout<<d<<endl;
	return 0;
}
