#include<cstdio>
const int MAXN=105;
int n,a[MAXN],ans;
inline int MAX(int a,int b)
{return a>b?a:b;}
int max(int a,int b,int c)
{return MAX(a,MAX(b,c));}
void solve()
{
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
			{
				int len=a[i]+a[j]+a[k];
				int ma=max(a[i],a[j],a[k]);
				int rest=len-ma;
				if(ma<rest) ans=MAX(ans,len);
			}
	printf("%d\n",ans);
}
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
}
int main()
{
	init();
	solve();
	return 0;
}
