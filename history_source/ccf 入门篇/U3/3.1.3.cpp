#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	int n,a,b,c,m;
	while(true){
		cin>>n;
		a=n/100;
		b=n/10-a*10;
		c=n-a*100-b*10;
		m=a*a*a+b*b*b+c*c*c;
		if(n==m)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
} 
