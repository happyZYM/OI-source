#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=205;
int T,kase,n,a[maxn],f[maxn][maxn][maxn],b[maxn],c[maxn],tot;
int dp(int i,int j,int k)
{
	int &res=f[i][j][k];
	if(res) return res;
	if(i==j) return res=(c[i]+k)*(c[i]+k);
	res=dp(i,j-1,0)+(k+c[j])*(k+c[j]);
	for(int p=i;p<j;p++)
		if(b[p]==b[j]) res=max(res,dp(i,p,k+c[j])+dp(p+1,j-1,0));
	return res;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		tot=0;
		int lst=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=lst) { b[++tot]=a[i]; c[tot]=1; lst=a[i]; }
			else c[tot]++;
		}
		memset(f,0,sizeof(f));
		for(int i=1;i<=tot;i++) f[i][i][0]=c[i]*c[i];
		printf("Case %d: %d\n",++kase,dp(1,tot,0));
	}
	return 0;
}