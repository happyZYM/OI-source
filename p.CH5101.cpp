//https://www.acwing.com/problem/content/274/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=3005;
int n,a[maxn],b[maxn],f[maxn][maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	a[0]=b[0]=-2147483647;
	int val;
	for(int i=1;i<=n;i++)
	{
		val=0;
		if(b[0]<a[i]) val=f[i-1][0];
		for(int j=1;j<=n;j++)
		{
			if(a[i]==b[j]) f[i][j]=val+1;
			else f[i][j]=f[i-1][j];
			if(b[j]<a[i]) val=max(val,f[i-1][j]);
		}
	}
	val=0;
	for(int j=1;j<=n;j++) val=max(val,f[n][j]);
	printf("%d\n",val);
	return 0;
}