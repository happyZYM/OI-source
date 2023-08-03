#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2005;
int n,a[maxn],f[maxn][maxn],b[maxn],tot;
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) { scanf("%d",&a[i]); b[i]=a[i]; }
	sort(b+1,b+n+1);
	tot=unique(b+1,b+n+1)-(b+1);
	int val; memset(f,0x3f,sizeof(f)); f[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		val=f[i][0];
		for(int j=1;j<=tot;j++)
		{
			val=min(val,f[i-1][j]);
			f[i][j]=val+abs(a[i]-b[j]);
		}
	}
	val=0x3f3f3f3f;
	for(int j=1;j<=tot;j++) val=min(val,f[n][j]);
	printf("%d\n",val);
	return 0;
}