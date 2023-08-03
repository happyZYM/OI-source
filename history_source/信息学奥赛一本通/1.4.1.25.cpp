#include<iostream>
#include<vector>
using namespace std;
int main()
{
	string days[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	int a,b;
	cin>>a>>b;
	int x=a;
	for(int i=1;i<b;i++)
	{
		a=a*x;
		a=a%7;
	}
	cout<<days[a]<<endl;
	return 0;
}
