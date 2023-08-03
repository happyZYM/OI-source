#include<cstdio>
int f[40],g[40],n;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	g[0]=1;g[1]=2;g[2]=4;
	for(n=3;n<=30;n++)
	{
		f[n]=1<<(n-3);
		for(int i=2;i<=n-2;i++) f[n]+=g[i-2]<<n-i-2;
		g[n]=(1<<n)-f[n];
	}
	while(scanf("%d",&n)==1&&n) printf("%d\n",f[n]);
	return 0;
}
