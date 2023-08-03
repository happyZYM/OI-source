#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll a,b;
bool is_prime[1000001],is_prime_small[1000001];
void solve()
{
	ll i,j,ans=0;
	memset(is_prime_small,1,sqrt(b));
	memset(is_prime,1,b-a);
	for(i=2;i*i<b;i++)
		if(is_prime_small[i])
		{
			for(j=2*i;j*j<b;j+=i) is_prime_small[j]=0;
			for(j=max(2LL,(a+i-1)/i)*i;j<b;j+=i) is_prime[j-a]=0;
		}
	for(i=a;i<b;i++) ans+=is_prime[i-a];
	printf("%lld\n",ans);
}
int main()
{
	scanf("%lld%lld",&a,&b);
	solve();
	return 0;
}
//22 37
//22801763489 22801787297
