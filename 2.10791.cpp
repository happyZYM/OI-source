#include<iostream>
#include<cmath>
using namespace std;
int dva(int &n,int d)
{
	int x=1;
	while(n%d==0)
	{
		n/=d;
		x*=d;
	}
	return x;
}
long long solve(int n)
{
	if(n==1) return 2;
	int m=int(sqrt(n)+0.5);
	long long ans=0;
	int cnt=0;
	for(int i=2;i<m;i++)
		if(n%i==0)
		{
			cnt++;
			ans+=dva(n,i);
		}
	if(n>1)
	{
		cnt++;
		ans+=n;
	}
	if(cnt<=1) ans++;
	return ans;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int n,kase=0;
	while(cin>>n&&n)
		cout<<"Case "<<++kase<<": "<<solve(n)<<"\n";
	return 0;
}
