#include<iostream>
using namespace std;
void hanio(int n,char a,char b,char c)
{
	if(n==1)
	{
		cout<<a<<"->1->"<<c<<'\n';
		return;
	}
	hanio(n-1,a,c,b);
	cout<<a<<"->"<<n<<"->"<<c<<'\n';
	hanio(n-1,b,a,c);
}
int main()
{
	ios::sync_with_stdio(0);
	int n;
	char a,b,c;
	cin>>n>>a>>b>>c;
	hanio(n,a,c,b);
	cout<<flush;
	return 0;
}
