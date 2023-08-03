//http://contest-hunter.org:83/contest/0x00%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E4%BE%8B%E9%A2%98/0201%20%E8%B4%B9%E8%A7%A3%E7%9A%84%E5%BC%80%E5%85%B3
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char mp[10][10],bk[10][10];
#define flip(x) (x)=('0'+1-((x)-'0'))
inline void cli(int r,int c)
{
	mp[r][c]^=1;
	mp[r-1][c]^=1;
	mp[r+1][c]^=1;
	mp[r][c-1]^=1;
	mp[r][c+1]^=1;
}
inline int cal(int st)
{
	memcpy(mp,bk,sizeof(mp));
	int cnt=0;
	for(int i=1;i<=5;i++) if((st>>i)&1) { cli(1,i); cnt++; }
	for(int i=2;i<=5;i++) for(int j=1;j<=5;j++) if(!mp[i-1][j]) { cli(i,j); cnt++; }
	for(int i=1;i<=5;i++) for(int j=1;j<=5;j++) if(!mp[i][j]) return 7;
	return cnt;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	while(n-->0)
	{
		for(int i=1;i<=5;i++)
		{
			scanf("%s",mp[i]+1);
			for(int j=1;j<=5;j++) mp[i][j]-='0';
		}
		memcpy(bk,mp,sizeof(bk));
		int res=7;
		for(int i=0;i<(1<<5);i++)
			res=min(res,cal(i<<1));
		if(res==7) res=-1;
		printf("%d\n",res);
	}
	return 0;
}
