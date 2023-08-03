#include<cstdio>
#include<cstring>
typedef long long LL;
const LL mod=1e9+7;
const int maxn=105;
int n;
LL k;
inline void times(LL a[maxn][maxn],LL b[maxn][maxn],LL c[maxn][maxn])
{
	memset(c,0,sizeof(LL)*maxn*maxn);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				c[i][j]=(a[i][k]*b[k][j]+c[i][j])%mod;
}
inline void ksm(LL a[maxn][maxn],LL k,LL res[maxn][maxn],LL tmp[maxn][maxn])
{
	memset(res,0,sizeof(LL)*maxn*maxn);
	for(int i=0;i<n;i++) res[i][i]=1;
	for(;k>0;k>>=1)
	{
		if(k&1) { times(res,a,tmp); memcpy(res,tmp,sizeof(LL)*maxn*maxn); }
		times(a,a,tmp); memcpy(a,tmp,sizeof(LL)*maxn*maxn);
	}
}
LL a[maxn][maxn],res[maxn][maxn],tmp[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%lld",&a[i][j]);
	ksm(a,k,res,tmp);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%lld ",res[i][j]);
		printf("\n");
	}
	return 0;
}
