#include<cstdio>
#define ll long long
ll n;
bool isp(ll n)
{
	static ll i;
	for(i=2;i*i<=n;i++) if(n%i==0) return 0;
	return n>1;
}
ll mod_pow(ll x,ll n,ll mod)
{
	static ll res;
	res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int solve()
{
	if(isp(n)) return printf("No\n");
	for(ll i=2;i<n;i++) if(mod_pow(i,n,n)!=i) return printf("No\n");
	printf("Yes\n");
}
int main()
{
	scanf("%lld",&n);
	solve();
	return 0;
}
