//http://contest-hunter.org:83/contest/0x29%E3%80%8C%E6%90%9C%E7%B4%A2%E3%80%8D%E7%BB%83%E4%B9%A0/2907%20%E4%B9%B3%E8%8D%89%E7%9A%84%E5%85%A5%E4%BE%B5
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
char mp[105][105];
int r,c,mr,mc,res,vis[105][105];
struct Node { int r,c,s; };
const int dr[8]={-1,-1,-1,0,1,1,1,0};
const int dc[8]={-1,0,1,1,1,0,-1,-1};
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d%d",&c,&r,&mc,&mr);
	mr=r-mr+1;
	for(int i=1;i<=r;i++) scanf("%s",mp[i]+1);
	vis[mr][mc]=true;
	queue<Node> Q;
	Q.push((Node){mr,mc,0});
	while(Q.size())
	{
		Node u=Q.front(); Q.pop();
		for(int i=0;i<8;i++)
		{
			int nr=u.r+dr[i],nc=u.c+dc[i];
			if(nr<1||nr>r||nc<1||nc>c||vis[nr][nc]||mp[nr][nc]=='*') continue;
			res=max(res,u.s+1);
			vis[nr][nc]=true;
			Q.push((Node){nr,nc,u.s+1});
		}
	}
	printf("%d\n",res);
	return 0;
}
