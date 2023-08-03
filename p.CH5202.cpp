#include<cstdio>
typedef long long LL;
LL f[4005],mod=2147483648ll;
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	int n; scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			(f[j]+=f[j-i])%=mod;
	printf("%lld\n",(f[n]+mod-1)%mod);
	return 0;
}