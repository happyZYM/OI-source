#include<cstdio>
#include<cstring>
#include<cassert>
typedef long long LL;
const LL mod=19260817;
char str[10005];
LL a,b,inv_b;
LL gcd(LL a,LL b) { return b==0?a:gcd(b,a%b); }
LL pow(LL a,int n)
{
	LL res=1;
	for(;n>0;n>>=1)
	{
		if(n&1) res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
int main()
{
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;i++) a=(a*10+str[i]-'0')%mod;
	scanf("%s",str);
	len=strlen(str);
	for(int i=0;i<len;i++) b=(b*10+str[i]-'0')%mod;
	if(gcd(b,mod)!=1) printf("Angry!\n");
	else
	{
		inv_b=pow(b,mod-2);
		printf("%lld\n",a*inv_b%mod);
	}
	return 0;
}
