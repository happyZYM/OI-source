#include<cstdio>
#define maxn 200
int fa[maxn+1],n,t,i,j,k,ans;
bool w[maxn+1][maxn+1];
int main()
{
	freopen("cdrom.in","r",stdin);
	freopen("cdrom.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		while(scanf("%d",&t),t>0) w[i][t]=1;
		fa[i]=i;
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				w[i][j]=w[i][j]||(w[i][k]&&w[k][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(w[i][j]) fa[j]=fa[i];
	for(i=1;i<=n;i++) if(fa[i]==i) ans++;
	printf("%d\n",ans);
	return 0;
}
