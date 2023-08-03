#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int a,b,c; cin>>a>>b>>c;
	int x=max(max(a,b),c);
	if(a==x) swap(a,c);
	if(b==x) swap(b,c);
	if(a>b) swap(a,b);
	int d=__gcd(a,c);
	a/=d; c/=d;
	cout<<a<<'/'<<c<<endl;
	return 0;
}
