#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 15 + 5, INF = 10;
int n, x, y, ans, num, C;
int m[maxn][maxn], v[maxn];
bool two(int s)
{
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
            if (m[i][j] && !(s & (1 << i)) && !(s & (1 << j)))
            {
                ++cnt;
                if (cnt == 3)
                    return true;
            }
    }
    return false;
}
bool DFS(int x, int f, int s)
{
    v[x] = 1;
    for (int i = 0; i < n; ++i)
        if (m[x][i] && !(s & (1 << i)))
        {
            if (!v[i])
            {
                if (DFS(i, x, s))
                    return true;
            }
            else if (i != f)
                return true;
        }
    return false;
}
bool circle(int s)
{
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; ++i)
        if (!v[i] && !(s & (1 << i)))
        {
            if (DFS(i, -1, s))
                return true;
            ++num;
        }
    return false;
}
int calc(int s)
{
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s & 1)
            ++res;
        s >>= 1;
    }
    return res;
}
int main()
{
    while (scanf("%d", &n)==1&&n)
    {
        ans = n;
        memset(m, 0, sizeof(m));
        while (scanf("%d%d", &x, &y), x != -1 && y != -1)
        {
            m[x - 1][y - 1] = 1;
            m[y - 1][x - 1] = 1;
        }
        for (int i = 0; i < (1 << n); ++i)
        {
            num = 0;
            if (two(i) || circle(i))
                continue;
            int tmp = calc(i);
            if (num - 1 <= tmp)
                ans = min(ans, tmp);
        }
        printf("Set %d: Minimum links to open is %d\n", ++C, ans);
    }
    return 0;
}
