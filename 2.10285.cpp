#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxr=105,maxc=105;
int r,c,res;
char name[1005];
int mp[maxr][maxc];
int d[maxr][maxc];
const int dx[]={+1,-1,+0,+0};
const int dy[]={+0,+0,+1,-1};
int dp(int x,int y)
{
	if(x<1||x>r||y<1||y>c) return 0;
	if(d[x][y]>-1) return d[x][y];
	d[x][y]=1;
	for(int i=0;i<4;i++)
		if(mp[x][y]>mp[x+dx[i]][y+dy[i]])
			d[x][y]=max(d[x][y],1+dp(x+dx[i],y+dy[i]));
	return d[x][y];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s%d%d",name,&r,&c);
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				scanf("%d",&mp[i][j]);
		memset(d,-1,sizeof(d));
		res=1;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				res=max(res,dp(i,j));
		printf("%s: %d\n",name,res);
	}
	return 0;
}
