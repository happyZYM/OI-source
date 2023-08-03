#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 10005;
const int D[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
char name[25];

int n, m;
vector<int> g[15][15][4];

struct State {
	int x, y, dir;
	int pre;
} Q[N], s, e;

char str[25];
int x, y, vis[15][15][4];

int Hash(char c) {
	if (c == 'F') return 0;
	if (c == 'R') return 1;
	if (c == 'L') return -1;
	if (c == 'N') return 0;
	if (c == 'E') return 1;
	if (c == 'S') return 2;
	return 3;
}

#define MP(a,b) make_pair(a,b)
typedef pair<int, int> pii;
vector<pii> ans;

void print(int u) {
	if (u == -1) return;
	print(Q[u].pre);
	ans.push_back(MP(Q[u].x, Q[u].y));
}

void bfs() {
	ans.clear();
	memset(vis, 0, sizeof(vis));
	int head = 0, rear = 0; s.pre = -1;
	Q[rear++] = s;
	vis[s.x][s.y][s.dir] = 1;
	while (head < rear) {
		State u = Q[head++];
		if (u.x == e.x && u.y == e.y) {
			print(head - 1);
			int tot = ans.size();
			for (int i = 0; i < tot; i++) {
				if (i % 10 == 0) printf("\n ");
				printf(" (%d,%d)", ans[i].first, ans[i].second);
			}
			printf("\n");
			return;
		}
		for (int i = 0; i < g[u.x][u.y][u.dir].size(); i ++) {
			int di = (g[u.x][u.y][u.dir][i] + u.dir + 4) % 4;
			State v = u;
			v.x += D[di][0]; v.y += D[di][1];
			if (v.x < 0 || v.y < 0) continue;
			v.dir = di;
			if (vis[v.x][v.y][v.dir]) continue;
			vis[v.x][v.y][v.dir] = 1;
			v.pre = head - 1;
			Q[rear++] = v;
		}
	}
	printf("\n  No Solution Possible\n");
}

int main() {
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while (~scanf("%s", name) && strcmp(name, "END")) {
		memset(g, 0, sizeof(g));
		printf("%s", name);
		scanf("%d%d%s", &s.x, &s.y, str);
		s.dir = Hash(str[0]);
		scanf("%d%d", &e.x, &e.y);
		g[s.x][s.y][Hash(str[0])].push_back(0);
		int x, y;
		while (scanf("%d", &x) && x) {
			scanf("%d", &y);
			while (scanf("%s", str) && str[0] != '*') {
				int len = strlen(str);
				for (int i = 1; i < len; i++)
					g[x][y][Hash(str[0])].push_back(Hash(str[i]));
			}
		}
		bfs();
	}
	return 0;
}
