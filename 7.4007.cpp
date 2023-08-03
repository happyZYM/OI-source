#include<cstdio>
#include<cstring>
using namespace std;
int n,mp[8][8],st[8][8],lim;
const int dr[]={-1,0,1,0};
const int dc[]={0,1,0,-1};
void link(int r,int c,int cl)
{
	st[r][c]=1;
	for(int i=0;i<4;i++)
	{
		int nr=r+dr[i],nc=c+dc[i];
		if(nr<0||nc<0||nr>=n||nc>=n||st[nr][nc]==1) continue;
		st[nr][nc]=2;
		if(mp[nr][nc]==cl) link(nr,nc,cl);
	}
}
int lst()
{
	int cnt[6]={0},tot=0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(!cnt[mp[i][j]]&&st[i][j]!=1) { cnt[mp[i][j]]=1; tot++; }
	return tot;
}
int fill(int cl)
{
	int cnt=0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(mp[i][j]==cl&&st[i][j]==2)
	{
		cnt++;
		link(i,j,cl);
	}
	return cnt;
}
bool dfs(int d)
{
	int g=lst();
	if(d+g>lim) return false;
	if(g==0) return true;
	int bk[8][8];
	for(int i=0;i<=5;i++)
	{
		memcpy(bk,st,sizeof(bk));
		if(fill(i)&&dfs(d+1)) return true;
		memcpy(st,bk,sizeof(st));
	}
	return false;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&mp[i][j]);
		memset(st,0,sizeof(st));
		link(0,0,mp[0][0]);
		for(lim=0;;lim++) if(dfs(0)) { printf("%d\n",lim); break; }
	}
	return 0;
}
