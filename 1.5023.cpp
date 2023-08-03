#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
int n,m;
LL ksm(LL a,LL b)
{
	LL res=1;
	for(;b>0;b>>=1,a=a*a%mod) b&1?res=res*a%mod:0;
	return res;
}
const LL v[9]={0,2,12,112,912,7136,56768,453504,3626752};
int main()
{
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	if(n==1) { printf("%lld\n",ksm(2,m)); return 0; }
	if(n==2) { printf("%lld\n",4*ksm(3,m-1)%mod); return 0; }
	if(n==m) { printf("%lld\n",v[n]); return 0; }
	if(n<4) printf("%lld\n",v[n]*ksm(3,m-n)%mod);
	else printf("%lld\n",(v[n]-ksm(2,n))*3*ksm(3,m-n-1)%mod);
	return 0;
}
