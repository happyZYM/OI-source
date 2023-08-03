#include<cstdio>
const int maxn=25;
int n,res,u,f[maxn],a[maxn],p[maxn],g[maxn][maxn];
void print(int u)
{
	if(u==0) return;
	print(p[u]);
	printf("%d ",u);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			scanf("%d",&g[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(g[j][i]&&f[i]<f[j])
			{
				f[i]=f[j];
				p[i]=j;
			}
		f[i]+=a[i];
		if(f[i]>res)
		{
			res=f[i];
			u=i;
		}
	}
	print(u); printf("\n%d\n",res);
	return 0;
}
