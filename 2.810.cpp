#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int D[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
const int N = 15;
char str[25];
int n, m, sx, sy, u, f, g[N][N];
int vis[N][N][7][7];
int to[7][7];
struct State
{
	int x, y, u, f;//×ø±ê£¬¶¥Ãæ£¬ÕýÃæ
	int pre;//¸¸½áµã±àºÅ
	State(){}
	State(int x, int y, int u, int f, int pre)
	{
		this->x = x;
		this->y = y;
		this->u = u;
		this->f = f;
		this->pre = pre;
	}
}q[10005];

void tra(int&vu, int&vf, int d)
{
	if (d == 0){ int tmp = vf; vf = 7 - vu; vu = tmp; }//ÏòÉÏ
	if (d == 1){ int tmp = vu; vu = 7 - vf; vf = tmp; }//ÏòÏÂ
	if (d == 2)vu = 7 - to[vu][vf];//ÏòÓÒ
	if (d == 3)vu = to[vu][vf];//Ïò×ó
}
typedef pair<int, int>P;
vector<P>ans;
void print(int u)//µÝ¹éÑ°ÕÒ¸ù½áµã£¬ºÃ´¦ÊÇÈë¶ÓÁÐË³ÐòÕýºÃÊÇË³ÐòµÄ£¬²»¹ýÖ»ÊÊÓÃÓÚÂ·¾¶½Ï¶ÌµÄÇé¿ö
{
	if (u == -1)return;
	print(q[u].pre);
	ans.push_back(P(q[u].x, q[u].y));
}
void bfs()
{
	ans.clear();
	int head = 0, rear = 0;
	q[rear++] = State(sx, sy, u, f, -1);
	memset(vis, 0, sizeof(vis));
	vis[sx][sy][u][f] = 1;
	while (head < rear)
	{
		State u = q[head++];//³ö¶ÓÁÐ
		for (int i = 0; i < 4; i++)
		{
			State v = u;
			v.x += D[i][0], v.y += D[i][1];
			if (v.x <= 0 || v.x>n || v.y <= 0 || v.y>m)continue;
			if (g[v.x][v.y] != -1 && u.u != g[v.x][v.y])continue;
			if (v.x == sx&&v.y == sy)
			{
				print(head - 1);//ÑØ×Å¸¸½áµãÕÒµ½¸ù
				ans.push_back(P(sx, sy));//ÓÉÓÚ
				int tot = ans.size();
				for (int i = 0; i < tot; i++)
				{
					if (i % 9 == 0)printf("\n  ");
					printf("(%d,%d)%c", ans[i].first, ans[i].second, i == tot - 1 ? '\n' : ',');
				}
				return;
			}
			tra(v.u, v.f, i);
			if (vis[v.x][v.y][v.u][v.f])continue;
			vis[v.x][v.y][v.u][v.f] = 1;//±ê¼Ç·ÃÎÊ¹ý
			v.pre = head - 1;//¼ÇÂ¼¸¸½áµã±àºÅ
			q[rear++] = v;//Èë¶ÓÁÐ
		}
	}
	printf("\n  No Solution Possible\n");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	to[1][2] = 4; to[1][3] = 2; to[1][4] = 5; to[1][5] = 3;//´ò±í£¬to[u][f]±íÊ¾¶¥ÃæÊÇu£¬ÕýÃæÊÇfÊ±µÄÓÒ²àÃæµÄÖµ
	to[2][1] = 3; to[2][3] = 6; to[2][4] = 1; to[2][6] = 4;
	to[3][1] = 5; to[3][2] = 1; to[3][5] = 6; to[3][6] = 2;
	to[4][1] = 2; to[4][2] = 6; to[4][5] = 1; to[4][6] = 5;
	to[5][1] = 4; to[5][3] = 1; to[5][4] = 6; to[5][6] = 3;
	to[6][2] = 3; to[6][3] = 5; to[6][4] = 2; to[6][5] = 4;
	while (~scanf("%s", str) && strcmp(str, "END"))
	{
		printf("%s", str);
		scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &u, &f);
		for (int i = 1; i <= n;i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &g[i][j]);
		bfs();
	}
	return 0;
}
