#include<iostream>
#include<cmath>
using namespace std;
bool z(int a)
{
	for(int i=2;i*i<=a;i++) if(a%i==0) return 0;
	return 1;
}
int main()
{
	int a,b;
	bool d;
	while(true)
	{
		d=1;
		cin>>a>>b;
		for(int i=2;i<=((a<b)?a:b);i++) 
		{
			if(z(i)){
			if(b%i==0)
			{
				if(a%i!=0) d=0;
			}}
		}
		if(d) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
