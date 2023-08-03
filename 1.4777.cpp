#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100005;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0) { x=1; y=0; return a; }
	LL d=exgcd(b,a%b,x,y);
	LL z=x; x=y; y=z-(a/b)*y;
	return d;
}
inline LL mmul(LL a, LL b, LL m)
{
    LL d=((long double)a/m*b+1e-8);
    LL r=a*b-d*m;
    return r<0?r+m:r;
}
int n;
LL ai[maxn],bi[maxn];
/*
i=1...n
x = ai ( mod bi )
*/
LL excrt()
{
	LL x,y,M=bi[1],res=ai[1];
	for(int i=2;i<=n;i++)
	{
		LL a=M,b=bi[i],c=((ai[i]-res)%b+b)%b;
		LL gcd=exgcd(a,b,x,y),b_g=b/gcd;
		if(c%gcd) return -1;
		x=mmul(x,c/gcd,b_g);
		res+=x*M;
		M*=b_g;//M=lcm(M,b)
		res=(res%M+M)%M;
	}
	return (res%M+M)%M;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&bi[i],&ai[i]);
	printf("%lld\n",excrt());
	return 0;
}
