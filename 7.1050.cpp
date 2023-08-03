#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=105;
int n,a[maxn][maxn],s[maxn][maxn],res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) s[i][j]=s[i][j-1]+a[i][j];
	res=s[1][1];
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)
	{
		int tot=s[1][j]-s[1][i-1],now=tot;
		for(int k=2;k<=n;k++)
		{
			if(tot<0) tot=0;
			tot+=s[k][j]-s[k][i-1];
			now=max(tot,now);
		}
		res=max(now,res);
	}
	printf("%d\n",res);
	return 0;
}
