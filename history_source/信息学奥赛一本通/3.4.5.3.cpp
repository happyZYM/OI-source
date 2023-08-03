#include<cstdio>
#define maxn 10000
int fa[maxn+1],n,m,ww,dp[maxn+1],sum,i,j,k,c[maxn+1],d[maxn+1],w[maxn+1],v[maxn+1];
int ff(int x)
{
	static int t1,t2;
	t1=x;
	while(fa[x]!=x) x=fa[x];
	while(t1!=x)
	{
		t2=fa[t1];
		fa[t1]=x;
		t1=t2;
	}
	return x;
}
void u(int a,int b)
{
	static int aa,bb;
	aa=ff(a);
	bb=ff(b);
	if(aa!=bb)
	{
		fa[bb]=aa;
		c[aa]+=c[bb];
		d[aa]+=d[bb];
		sum--;
	}
}
inline int max(int a,int b)
{return a>b?a:b;}
int main()
{
	freopen("buy.in","r",stdin);
	freopen("buy.out","w",stdout);
	scanf("%d%d%d",&n,&m,&ww);
	sum=n;
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=n;i++) scanf("%d%d",c+i,d+i);
	int a,b;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		u(a,b);
	}
	k=1;
	for(i=1;i<=n;i++)
		if(fa[i]==i)
		{
			w[k]=c[i];
			v[k++]=d[i];
		}
	for(i=1;i<=sum;i++)
		for(j=ww;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	printf("%d\n",dp[ww]);
	return 0;
}
