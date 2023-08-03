#include<cstdio>
int n,m,a[1005],f[10005];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=a[i];j--)
			f[j]+=f[j-a[i]];
	printf("%d\n",f[m]);
	return 0;
}