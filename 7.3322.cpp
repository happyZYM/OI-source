#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct DT { int x,y,lie; };
char s[505][505];
DT st,ed;
int n,m,d[505][505][3];
queue<DT> Q;
const int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
inline bool valid(int x,int y) { return x>=1&&y>=1&&x<=n&&y<=m; }
void init()
{
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		if(s[i][j]=='O') { ed.x=i; ed.y=j; ed.lie=0; s[i][j]='.'; }
		else if(s[i][j]=='X')
		{
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k],y=j+dy[k];
				if(valid(x,y)&&s[x][y]&&s[x][y]=='X')
				{
					st.x=min(i,x),st.y=min(j,y);
					st.lie=k<2?1:2;
					s[i][j]=s[x][y]='.';
					break;
				}
			}
			if(s[i][j]=='X') st.x=i,st.y=j,st.lie=0;
		}
}
inline bool valid(DT nxt)
{
	if(!valid(nxt.x,nxt.y)) return 0;
	if(s[nxt.x][nxt.y]=='#') return 0;
	if(nxt.lie==0&&s[nxt.x][nxt.y]!='.') return 0;
	if(nxt.lie==1&&s[nxt.x][nxt.y+1]=='#') return 0;
	if(nxt.lie==2&&s[nxt.x+1][nxt.y]=='#') return 0;
	return 1;
}
const int nxt_x[3][4]={{0,0,-2,1},{0,0,-1,1},{0,0,-1,2}};
const int nxt_y[3][4]={{-2,1,0,0},{-1,2,0,0},{-1,1,0,0}};
const int nxt_lie[3][4]={{1,1,2,2},{0,0,1,1},{2,2,0,0}};

int bfs()
{
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=0;k<3;k++) d[i][j][k]=-1;
	while(Q.size()) Q.pop();
	d[st.x][st.y][st.lie]=0; Q.push(st);
	while(Q.size())
	{
		DT u=Q.front(); Q.pop();
		for(int i=0;i<4;i++)
		{
			DT nxt;
			nxt.x=u.x+nxt_x[u.lie][i];
			nxt.y=u.y+nxt_y[u.lie][i];
			nxt.lie=nxt_lie[u.lie][i];
			if(!valid(nxt)) continue;
			if(d[nxt.x][nxt.y][nxt.lie]==-1)
			{
				d[nxt.x][nxt.y][nxt.lie]=d[u.x][u.y][u.lie]+1;
				Q.push(nxt);
				if(nxt.x==ed.x&&nxt.y==ed.y&&nxt.lie==ed.lie) return d[nxt.x][nxt.y][nxt.lie];
			}
		}
	}
	return -1;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		init();
		int res=bfs();
		if(res==-1) puts("Impossible");
		else printf("%d\n",res);
	}
	return 0;
}
