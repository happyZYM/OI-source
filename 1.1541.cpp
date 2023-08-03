#include<cstdio>
#include<algorithm>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
const int maxn=41;
int n,m,x,g[5],num[351],f[maxn][maxn][maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&num[i]);
	f[0][0][0][0]=num[1];
	For(i,1,m) { scanf("%d",&x); ++g[x]; }
	For(a,0,g[1]) For(b,0,g[2]) For(c,0,g[3]) For(d,0,g[4])
	{
		int p=a+b*2+c*3+d*4+1,&now=f[a][b][c][d];
		if(a) now=max(now,f[a-1][b][c][d]+num[p]);
		if(b) now=max(now,f[a][b-1][c][d]+num[p]);
		if(c) now=max(now,f[a][b][c-1][d]+num[p]);
		if(d) now=max(now,f[a][b][c][d-1]+num[p]);
	}
	printf("%d\n",f[g[1]][g[2]][g[3]][g[4]]);
	return 0;
}
