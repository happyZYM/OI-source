#include <cstdio>
#include <cstring>
const int maxn = 999999;
int t = 0, v, sum, f;
int g[30][30], vis[30], floyd[30][30], rec[30];

void dfs(int x, int n) {
	if (x == f) {
		printf("1");
		for (int i = 1; i < n - 1; i++)
			printf(" %d", rec[i]);
		printf(" %d\n", f);
		sum++;
		return;
	}
	for (int i = 1; i <= v; i++) {
		if (!vis[i] && g[x][i] == 1 && floyd[f][i] != maxn) {
			rec[n] = i;
			vis[i] = 1;
			dfs(i, n + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	int x, y, cas = 1;
	while (scanf("%d", &f) != EOF) {
		v = 0;
		for (int i = 1; i <= 21; i++)
			for (int j = 1; j <= 21; j++)
				g[i][j] = floyd[i][j] = maxn;
		while (scanf("%d%d", &x, &y) && (x || y)) {
			g[x][y] = g[y][x] = 1;
			floyd[x][y] = floyd[y][x] = 1;
			if (x > v) v = x;
			if (y > v) v = y;
		}
		for (int k = 1; k <= v; k++)
			for (int i = 1; i <= v; i++)
				for (int j = 1; j <= v; j++)
					if (floyd[i][k] + floyd[k][j] < floyd[i][j])
						floyd[i][j] = floyd[i][k] + floyd[k][j];
		vis[1] = 1;
		sum = 0;
		printf("CASE %d:\n", cas++);
		dfs(1, 1);
		printf("There are %d routes from the firestation to streetcorner %d.\n", sum, f);
	}
	return 0;
}
