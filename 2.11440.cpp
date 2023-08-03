#include<cstdio>
#include<cmath>
const int maxn=10000010,MOD=100000007;
int vis[maxn],phifac[maxn];
void init(int n)
{
	int m=(int)sqrt(n+0.5),c=0,i,j;
	for(i=2;i<=m;i++)
		if(!vis[i])
			for(j=i*i;j<=n;j+=i) vis[j]=1;
}
int n,m,i,res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	init(10000000);
	phifac[1]=phifac[2]=1;
	for(i=3;i<=10000000;i++)
		phifac[i]=(long long)phifac[i-1]*(vis[i]?i:i-1)%MOD;
	while(scanf("%d%d",&n,&m)==2&&m&&n)
	{
		res=phifac[m];
		for(i=m+1;i<=n;i++) res=(long long)res*i%MOD;
		printf("%d\n",(res-1+MOD)%MOD);
	}
	return 0;
}
