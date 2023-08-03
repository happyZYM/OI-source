#include<iostream>
using namespace std;
int main()
{
	int n,a,b,c,a1,b1,c1;
	while(true)
	{
		a=0;
		b=0;
		c=0;
		cin>>n;
	    for(int i=0;i<n;i++)
	    {
		cin>>a1>>b1>>c1;
		a+=a1;
		b+=b1;
		c+=c1;
	    }
	    cout<<a<<" "<<b<<" "<<c<<" "<<a+b+c<<endl<<endl;
	}
}
