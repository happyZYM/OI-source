#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=305;
int n,a[maxn],s[maxn],f[maxn][maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
		s[i]=s[i-1]+a[i];
	}
	for(int len=2;len<=n;len++)
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			for(int k=l;k<r;k++) f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]);
			f[l][r]+=s[r]-s[l-1];
		}
	printf("%d\n",f[1][n]);
	return 0;
}