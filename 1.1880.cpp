#include<cstdio>
#include<algorithm>
using namespace std;
const int oo=1e9+7;
const int maxn=2007;
int a[maxn],sum[maxn];
int n,Fi[maxn][maxn],Fa[maxn][maxn],s[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i]; s[i][i]=i; a[i+n]=a[i];
	}
	for(int i=1+n;i<=n*2;i++)
	{
		sum[i]=sum[i-1]+a[i];
		s[i][i]=i;
	}
	for(int i=n*2-1;i>=1;i--)
		for(int j=i+1;j<=n*2;j++)
		{
			int &pos=s[i][j],&val=Fi[i][j]; val=oo;
			Fa[i][j]=max(Fa[i+1][j],Fa[i][j-1])+(sum[j]-sum[i-1]);
			for(int k=s[i][j-1];k<=s[i+1][j];k++)
			{
				int tmp=Fi[i][k]+Fi[k+1][j]+(sum[j]-sum[i-1]);
				if(tmp<val) val=tmp,pos=k;
			}
		}
	int res_ma=0,res_mi=oo;
	for(int i=1;i<=n;i++)
	{
		res_ma=max(res_ma,Fa[i][i+n-1]);
		res_mi=min(res_mi,Fi[i][i+n-1]);
	}
	printf("%d\n%d\n",res_mi,res_ma);
	return 0;
}
/*
4
4 5 9 4
*/
