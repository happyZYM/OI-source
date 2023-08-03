//http://acm.hdu.edu.cn/showproblem.php?pid=5015
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int P=10000007;
const int SIZE=1152;
int n,m;
LL v[12],a[12][12],b[12][12];
inline void mul(LL a[12][12],LL b[12][12],LL c[12][12])
{
	memset(c,0,SIZE);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
			(c[i][j]+=a[i][k]*b[k][j])%=P;
}
inline void ksm(LL a[12][12],LL b,LL c[12][12])
{
	LL t[12][12];
	memset(c,0,SIZE); for(int i=0;i<n;i++) c[i][i]=1;
	for(;b;b>>=1)
	{
		if(b&1) { mul(c,a,t); memcpy(c,t,SIZE); }
		mul(a,a,t); memcpy(a,t,SIZE);
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2)
	{
		n+=2;
		for(int i=2;i<n;i++) scanf("%d",&v[i]);
		v[0]=1; v[1]=233;
		for(int i=2;i<n;i++) (v[i]+=v[i-1])%=P;
//		printf("v: "); for(int i=0;i<n;i++) printf("%d ",v[i]); puts("");
		memset(a,0,SIZE);
		a[0][0]=1;
		for(int i=2;i<n;i++) for(int j=2;j<=i;j++) a[i][j]=1;
		for(int i=1;i<n;i++) a[i][0]=3;
		for(int i=1;i<n;i++) a[i][1]=10;
//		printf("a:\n");
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<n;j++) printf("%d ",a[i][j]);
//			puts("");
//		}
//		printf("m-1=%d\n",m-1);
		ksm(a,m-1,b);
		LL res=0;
		for(int i=0;i<n;i++)
		{
			(res+=b[n-1][i]*v[i])%=P;
//			printf("+=%lld*%lld\n",b[n-1][i],v[i]);
		}
		printf("%lld\n",res);
	}
	return 0;
}
