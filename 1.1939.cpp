#include<cstdio>
#include<cstring>
typedef long long LL;
const LL mod=1e9+7;
LL a[3][3],b[3][3],c[3][3];
void times(LL a[3][3],LL b[3][3],LL c[3][3])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			c[i][j]=0;
			for(int k=0;k<3;k++) c[i][j]+=a[i][k]*b[k][j];
			c[i][j]%=mod;
		}
}
void ksm(LL a[3][3],int n,LL b[3][3],LL tmp[3][3])
{
	memset(b,0,sizeof(LL)*3*3);
	for(int i=0;i<3;i++) b[i][i]=1;
	for(;n>0;n>>=1)
	{
		if(n&1) { times(a,b,tmp); memcpy(b,tmp,sizeof(LL)*3*3); }
		times(a,a,tmp); memcpy(a,tmp,sizeof(LL)*3*3);
	}
}
int T,n;
void print(LL a[3][3])
{
	for(int i=0;i<3;i++,puts(""))
		for(int j=0;j<3;j++) printf("%3d",a[i][j]);
	puts("");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		if(n<=3) { puts("1"); continue; }
		a[0][0]=a[0][2]=a[1][0]=a[2][1]=1;
		a[0][1]=a[1][1]=a[1][2]=a[2][0]=a[2][2]=0;
		ksm(a,n-3,b,c);
		printf("%lld\n",(b[0][0]+b[0][1]+b[0][2])%mod);
	}
	return 0;
}
