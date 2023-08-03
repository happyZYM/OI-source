#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int oo=0x3f3f3f3f;
const int maxn=105;
int n,a[maxn],op[maxn],f[2][maxn][maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char s[2]; int x; scanf("%s%d",s,&x);
		op[i-1]=(s[0]=='t'?0:1); a[i]=x;
	}
	for(int i=1;i<=n;i++) { a[n+i]=a[i]; op[n+i-1]=op[i-1]; }
	for(int i=1;i<=n*2-1;i++) for(int j=i;j<=n*2-1;j++) { f[0][i][j]=-oo; f[1][i][j]=oo; }
	for(int i=1;i<=n*2-1;i++) f[0][i][i]=f[1][i][i]=a[i];
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n*2-1;i++)
		{
			int j=i+len-1;
			for(int k=i;k<j;k++)
			{
				if(!op[k])
				{
					f[0][i][j]=max(f[0][i][j],f[0][i][k]+f[0][k+1][j]);
					f[1][i][j]=min(f[1][i][j],f[1][i][k]+f[1][k+1][j]);
				}
				else
				{
					f[0][i][j]=max(f[0][i][j],max(f[0][i][k]*f[0][k+1][j],f[1][i][k]*f[1][k+1][j]));
					f[1][i][j]=min(f[1][i][j],min(min(f[0][i][k]*f[0][k+1][j],f[1][i][k]*f[1][k+1][j]),min(f[0][i][k]*f[1][k+1][j],f[1][i][k]*f[0][k+1][j])));
				}
			}
		}
	int res=-oo;
	for(int i=1;i<=n;i++) res=max(res,f[0][i][i+n-1]);
	printf("%d\n",res);
	for(int i=1;i<=n;i++) if(f[0][i][i+n-1]==res) printf("%d ",i); puts("");
	return 0;
}