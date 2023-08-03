#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL mod=100000000;
LL n,m,a[2][2],c[2][2];
LL gcd(LL a,LL b)
{
    int ta,tb;
    while(b>0) ta=b,tb=a%b,a=ta,b=tb;
    return a;
}
inline void mul(LL a[2][2],LL b[2][2],LL c[2][2])
{
	for(int i=0;i<2;i++) for(int j=0;j<2;j++) c[i][j]=(a[i][0]*b[0][j]+a[i][1]*b[1][j])%mod;
}
inline void cp(LL a[2][2],LL b[2][2]) { b[0][0]=a[0][0]; b[0][1]=a[0][1]; b[1][0]=a[1][0]; b[1][1]=a[1][1]; }
inline void ksm(LL a[2][2],LL b,LL c[2][2])
{
	c[0][0]=c[1][1]=1; c[0][1]=c[1][0]=0;
	LL t[2][2];
	for(;b;b>>=1)
	{
		if(b&1) { mul(c,a,t); cp(t,c); }
		mul(a,a,t); cp(t,a);
	}
}
int main()
{
    scanf("%lld%lld",&n,&m);
    LL p=gcd(n,m);
	if(p==1||p==2) { puts("1"); return 0; }
	a[0][1]=a[1][0]=a[1][1]=1;
	ksm(a,p-2,c);
	printf("%lld\n",(c[1][0]+c[1][1])%mod);
    return 0;
}
