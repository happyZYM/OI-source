#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int dr[]={-1,1,0,0,-2,2,0,0,0};
const int dc[]={0,0,-1,1,0,0,-2,2,0};
int n,fe[366][4][4],can[366][3][3],vis[366][3][3][8][8][8][8];
inline bool Read()
{
	scanf("%d",&n);
	if(n==0) return false;
	for(int i=1;i<=n;i++)
		for(int r=0;r<4;r++) for(int c=0;c<4;c++)
			scanf("%d",&fe[i][r][c]);
	return true;
}
int DFS(int ti,int r,int c,int x1,int x2,int x3,int x4)
{
	if(ti==n) return 1;
	for(int i=0;i<9;i++)
	{
		int nr=r+dr[i],nc=c+dc[i];
#define A1 ((nr==0&&nc==0)?0:x1+1)
#define A2 ((nr==0&&nc==2)?0:x2+1)
#define A3 ((nr==2&&nc==2)?0:x3+1)
#define A4 ((nr==2&&nc==0)?0:x4+1)
		if(nr<0||nr>2||nc<0||nc>2||!can[ti+1][nr][nc]||vis[ti+1][nr][nc][A1][A2][A3][A4]) continue;
		if(A1<=6&&A2<=6&&A3<=6&&A4<=6)
		{
			vis[ti+1][nr][nc][A1][A2][A3][A4]=1;
			if(DFS(ti+1,nr,nc,A1,A2,A3,A4)) return 1;
		}
	}
	return 0;
}
void Solve()
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		for(int r=0;r<3;r++) for(int c=0;c<3;c++)
			can[i][r][c]=1-(fe[i][r][c]|fe[i][r+1][c]|fe[i][r][c+1]|fe[i][r+1][c+1]);
	if(n>1) printf("%d\n",DFS(1,1,1,1,1,1,1));
	else printf("%d\n",can[1][1][1]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(Read())
		Solve();
	return 0;
}
/*
1
0
0
1
1
1
0
0
1
0
1
0
0
0
0
0
0
0
0
1
0
1
0
0
1
0
0
*/
