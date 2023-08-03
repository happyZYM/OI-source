//http://contest-hunter.org:83/contest/0x00%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E4%BE%8B%E9%A2%98/0103%20%E6%9C%80%E7%9F%ADHamilton%E8%B7%AF%E5%BE%84
#include<cstdio>
#include<cstring>
using namespace std;
int n,G[20][20],f[1<<20][20];
void CheckMin(int &a,const int &b) { a=a<b?a:b; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&G[i][j]);
	memset(f,0x3f,sizeof(f));
	f[1][0]=0;
	for(int st=1;st<(1<<n);st++)
		for(int u=0;u<n;u++) if(st&(1<<u))
			for(int v=0;v<n;v++) if(u!=v&&!(st&(1<<v)))
				CheckMin(f[st|(1<<v)][v],f[st][u]+G[u][v]);
	printf("%d\n",f[(1<<n)-1][n-1]);
	return 0;
}
