#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	int x,y;
	while(true)
	{
		cin>>x>>y;
		x=abs(x);
		y=abs(y);
		if(x<=1&&y<=1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
