#include<iostream>
using namespace std;
int zd(int a,int b)
{
	return (b==0)?a:zd(b,a%b);
}
int zx(int a,int b)
{
	return a*b/zd(a,b);
}
int main()
{
	int n,m;
	while(true)
	{
		cin>>n>>m;
		cout<<zx(n,m)<<endl;
	}
} 
