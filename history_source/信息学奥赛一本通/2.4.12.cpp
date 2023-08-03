#include<iostream> 
using namespace std;
long long t;
long long gcd(long long a,long long b)
{
	if(a==b) return a;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	if(a&1)
	{
		if(b&1) return gcd(b,a-b);
		else return gcd(a,b>>1);
	}
	else
	{
		if(b&1) return gcd(a>>1,b);
		return 2*gcd(a>>1,b>>1);
	}
}
long long lcm(long long a,long long b)
{
	return a/gcd(a,b)*b;
}
struct fen
{
	long long a,b;
	fen operator+(fen bb)
	{
		fen aa;
		aa.a=a;
		aa.b=b;
		fen ans;
		ans.b=lcm(aa.b,bb.b);
		ans.a=ans.b/aa.b*aa.a+ans.b/bb.b*bb.a;
		long long gon=gcd(ans.a,ans.b);
		ans.a/=gon;
		ans.b/=gon;
		return ans;
	}
};
fen make_fen_li;
fen make_fen(long long a,long long b)
{
	make_fen_li.a=a;
	make_fen_li.b=b;
	return make_fen_li;
}
int main()
{
	int n;
	cin>>n;
	long long a,b;
	char li;
	cin>>a>>li>>b;
	fen ans;
	ans=make_fen(a,b);
	for(int i=1;i<n;i++)
	{
		cin>>a>>li>>b;
		ans=ans+make_fen(a,b);
	}
	if(ans.b!=1) printf("%lld/%lld\n",ans.a,ans.b);
	else printf("%lld\n",ans.a);
	return 0;
}

