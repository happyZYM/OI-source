#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=4000;
int N,B,U[maxn],f[2][maxn][2];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&N,&B);
	for(int i=1;i<=N;i++) scanf("%d",&U[i]);
	memset(f,0xcf,sizeof(f));
	f[1&1][0][0]=0; f[1&1][1][1]=0;
	for(int i=2;i<=N;i++)
		for(int j=0;j<=B&&j<=i;j++)
		{
			f[i&1][j][0]=max(f[i-1&1][j][0],f[i-1&1][j][1]);
			if(j>=1) f[i&1][j][1]=max(f[i-1&1][j-1][0],f[i-1&1][j-1][1]+U[i]);
		}
	int res=max(f[N&1][B][0],f[N&1][B][1]);
	memset(f,0xcf,sizeof(f));
	f[1&1][1][1]=U[1];
	for(int i=2;i<=N;i++)
		for(int j=0;j<=B&&j<=i;j++)
		{
			f[i&1][j][0]=max(f[i-1&1][j][0],f[i-1&1][j][1]);
			if(j>=1) f[i&1][j][1]=max(f[i-1&1][j-1][0],f[i-1&1][j-1][1]+U[i]);
		}
	printf("%d\n",max(res,f[N&1][B][1]));
	return 0;
}