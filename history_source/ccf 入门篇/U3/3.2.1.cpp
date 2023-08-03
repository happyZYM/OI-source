#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	int b,g;
	while(true)
	{
		cin>>b>>g;
		if((b+g)<10) cout<<"water"<<endl;
		else{
			if(b>g) cout<<"tree"<<endl;
			else cout<<"tea"<<endl;
		}
		
	}
}
