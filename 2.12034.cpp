#include<cstdio>
const int maxn=1000,MOD=10056; 
int C[maxn+1][maxn+1],f[maxn+1]={1};
int i,j,T,n;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(i=0;i<=maxn;i++)
	{
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	for(i=1;i<=maxn;i++)
		for(j=1;j<=i;j++)
			f[i]=(f[i]+C[i][j]*f[i-j])%MOD;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
		printf("Case %d: %d\n",kase,f[scanf("%d",&n),n]);
	return 0;
}
