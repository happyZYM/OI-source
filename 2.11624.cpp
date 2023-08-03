#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;++i)
const int maxn=1005;
const int oo=0x3f3f3f3f;
struct Node
{
	int r,c,t;
	Node(int R,int C,int T):r(R),c(C),t(T) { }
};
queue<Node> Q;
int T,n,m,p[maxn][maxn],vis[maxn][maxn],sr,sc;
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
char mp[maxn][maxn];
void init()
{
	while(Q.size())
	{
		Node u=Q.front();Q.pop();
		For(i,0,3)
		{
			int vr=u.r+dr[i],vc=u.c+dc[i];
			if((vr>=1&&vr<=n&&vc>=1&&vc<=m)&&mp[vr][vc]!='#'&&p[vr][vc]==oo)
			{
				Q.push(Node(vr,vc,0));
				p[vr][vc]=p[u.r][u.c]+1;
			}
		}
	}
}
void bfs()
{
	while(Q.size()) Q.pop();
	Q.push(Node(sr,sc,0));
	vis[sr][sc]=1;
	while(Q.size())
	{
		Node u=Q.front();Q.pop();
		if(u.r==n||u.r==1||u.c==1||u.c==m) { printf("%d\n",u.t+1); return; }
		For(i,0,3)
		{
			int vr=u.r+dr[i],vc=u.c+dc[i];
			if((vr>=1&&vr<=n&&vc>=1&&vc<=m)&&mp[vr][vc]!='#'&&!vis[vr][vc]&&(u.t+1<p[vr][vc]))
			{
				Q.push(Node(vr,vc,u.t+1));
				vis[vr][vc]=1;
			}
		}
	}
	puts("IMPOSSIBLE");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		while(Q.size()) Q.pop();
		memset(vis,0,sizeof(vis));
		memset(p,oo,sizeof(p));
		scanf("%d%d",&n,&m);
		For(i,1,n) scanf("%s",mp[i]+1);
		For(i,1,n) For(j,1,m)
		{
			if(mp[i][j]=='F')
			{
				Q.push(Node(i,j,0));
				p[i][j]=0;
			}
			if(mp[i][j]=='J') sr=i,sc=j;
		}
		init(); bfs();
	}
	return 0;
}
