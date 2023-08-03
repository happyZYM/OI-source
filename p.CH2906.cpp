//http://contest-hunter.org:83/contest/0x29%E3%80%8C%E6%90%9C%E7%B4%A2%E3%80%8D%E7%BB%83%E4%B9%A0/2906%20%E6%AD%A6%E5%A3%AB%E9%A3%8E%E5%BA%A6%E7%9A%84%E7%89%9B
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct Node { int r,c,s; };
int r,c,sr,sc;
char mp[200][200];
bool vis[200][200];
const int dr[8]={-2,-2,-1,1,2,2,1,-1};
const int dc[8]={-1,1,2,2,1,-1,-2,-2};
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&c,&r);
	for(int i=0;i<r;i++)
	{
		scanf("%s",mp[i]);
		for(int j=0;j<c;j++) if(mp[i][j]=='K') sr=i,sc=j;
	}
	queue<Node> Q;
	Q.push((Node){sr,sc,0});
	vis[sr][sc]=true;
	while(Q.size())
	{
		Node u=Q.front(); Q.pop();
//		printf("u=(%d,%d,%d)\n",u.r,u.c,u.s);
		for(int i=0;i<8;i++)
		{
			int nr=u.r+dr[i],nc=u.c+dc[i];
			if(nr<0||nr>=r||nc<0||nc>=c||mp[nr][nc]=='*'||vis[nr][nc]) continue;
			if(mp[nr][nc]=='H') { printf("%d\n",u.s+1); return 0; }
			vis[nr][nc]=true;
			Q.push((Node){nr,nc,u.s+1});
		}
	}
	return 0;
}
