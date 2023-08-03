#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define INT_MAX 10000000
int i,t,n,ans,maxprice,minprice;
int a[100005],dp1[100005],dp2[100005]; 
void read(int &x) 
{
	int f=1;x=0;
	char c=getchar();
	for (;!(c>='0'&&c<='9');c=getchar()) if(c=='-') f=-1;
	for (;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main() 
{
	read(t);
	while (t--) 
	{
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		ans=0; minprice=INT_MAX; read(n);
		for (i=1;i<=n;i++) read(a[i]);
		for (i=1;i<=n;i++) 
		{
			minprice=min(minprice,a[i]);
			dp1[i]=max(dp1[i-1],a[i]-minprice);
		}
		maxprice=-INT_MAX;
		for (i=n;i>=1;i--)
		{
			maxprice=max(maxprice,a[i]);
			dp2[i]=max(dp2[i+1],maxprice-a[i]);
		}
		for (i=1;i<=n;i++) ans=max(ans,dp1[i]+dp2[i+1]);
		printf("%d\n",ans);
	}
	return 0;
}
