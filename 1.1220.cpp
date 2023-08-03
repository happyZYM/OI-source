#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=55;
int n,c,p[maxn],w[maxn];
LL s[maxn],f[maxn][maxn][2];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&w[i]);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+w[i];
	memset(f,0x3f,sizeof(f));
	f[c][c][0]=f[c][c][1]=0;
	for(int len=1;len<n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			LL W=s[i-1]+s[n]-s[j];
			if(i>1) f[i-1][j][0]=min(f[i-1][j][0],min(f[i][j][0]+(p[i]-p[i-1])*W,f[i][j][1]+(p[j]-p[i-1])*W));
			if(j<n) f[i][j+1][1]=min(f[i][j+1][1],min(f[i][j][0]+(p[j+1]-p[i])*W,f[i][j][1]+(p[j+1]-p[j])*W));
		}
	printf("%lld\n",min(f[1][n][0],f[1][n][1]));
	return 0;
}