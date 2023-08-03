#include<cstdio>
int n,a[105][105],s[105][105],y[105],max,maxn,i,j,l,r,ans;
inline int Max(int a,int b){return a>b?a:b;}
int answer()
{
	for(j=1;j<=n;j++) y[j]=s[j][r]-s[j][l-1];
	max=maxn=y[1];
	for(j=2;j<=n;j++)
	{
		if(maxn<0) maxn=y[j];
		else maxn+=y[j];
		max=Max(max,maxn);
	}
	return max;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++) scanf("%d",&(a[j][i]));
	for(j=1;j<=n;j++)
		for(i=1;i<=n;i++) s[j][i]=s[j][i-1]+a[j][i];
	ans=a[1][1];
	for(l=1;l<=n;l++)
		for(r=l;r<=n;r++) ans=Max(ans,answer());
	printf("%d\n",ans);
	return 0;
}
