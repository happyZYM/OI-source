#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=22;
const int oo=11234567;
int n,m,k; 
bool mp[maxn][maxn];
int sum[maxn][maxn];
int d[maxn][maxn][maxn][maxn];
inline int getsum(int ax,int ay,int bx,int by)
{
	return sum[bx][by]-sum[ax-1][by]-sum[bx][ay-1]+sum[ax-1][ay-1];
}
inline bool err(int x,int y)
{
	return x<1||x>n||y<1||y>m;
}

int dp(int ax,int ay,int bx,int by)
{
	if(err(ax,ay)||err(bx,by)||ax>bx||ay>by) return 0;
	int &res=d[ax][ay][bx][by];
	if(res>-1) return res;
	if(getsum(ax,ay,bx,by)==1) return res=0;
	if(getsum(ax,ay,bx,by)<1) return res=oo;
	res=oo;
	for(int i=ax;i<bx;i++)
		res=min(res,by-ay+1+dp(ax,ay,i,by)+dp(i+1,ay,bx,by));
	for(int i=ay;i<by;i++)
		res=min(res,bx-ax+1+dp(ax,ay,bx,i)+dp(ax,i+1,bx,by));
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int kase=0;
	while(scanf("%d%d%d",&n,&m,&k)==3&&n&&m)
	{
		memset(mp,0,sizeof(mp));
		memset(sum,0,sizeof(sum));
		memset(d,-1,sizeof(d));
		for(int i=0;i<k;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			mp[x][y]=1;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mp[i][j];
		printf("Case %d: %d\n",++kase,dp(1,1,n,m));
	}
	return 0;
}
