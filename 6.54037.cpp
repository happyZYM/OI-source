#include<cstdio>
#include<cstring>
typedef long long LL;
const LL mod=1000000007;
LL a[2][2],b[2][2],c[2][2];
inline void times(LL a[2][2],LL b[2][2],LL c[2][2])
{
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		{
			c[i][j]=0;
			for(int k=0;k<2;k++) c[i][j]+=a[i][k]*b[k][j];
			c[i][j]%=mod;
		}
}
void ksm(LL a[2][2],int n,LL b[2][2],LL tmp[2][2])
{
	b[0][0]=b[1][1]=1; b[0][1]=b[1][0]=0;
	for(;n>0;n>>=1)
	{
		if(n&1) { times(a,b,tmp); memcpy(b,tmp,sizeof(LL)*2*2); }
		times(a,a,tmp); memcpy(a,tmp,sizeof(LL)*2*2);
	}
}
int T,n,m;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	if(m==1) { printf("%d\n",n); return 0; }
	a[0][0]=0; a[0][1]=1;
	a[1][0]=mod-1; a[1][1]=n;
	ksm(a,m-1,b,c);
	printf("%lld\n",(b[1][0]*2%mod+b[1][1]*n%mod)%mod); 
	return 0;
}
