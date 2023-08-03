#include<iostream>
using namespace std;
int main()
{
	int ans=0,a,b,c;
	cin>>a>>b>>c;
	for(int i=0;i<=c/a+1;i++)
	{
		for(int j=0;j<=(c-i*a)/b+1;j++)
			if(i*a+j*b==c) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

