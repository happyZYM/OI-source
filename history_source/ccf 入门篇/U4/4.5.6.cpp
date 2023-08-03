#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m,k,x;
	long long a;
	while(true)
	{
		cin>>n>>m>>k>>x;
		a=pow(10,k);
		k=a%n;
		cout<<(m*k+x)%n<<endl;
	}
}
