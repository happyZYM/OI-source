#include<stdio.h>
#include<string.h>
#define MAXD 510
#define INF 0x3fffffff
int a[MAXD], ans[MAXD], g[MAXD], min, N;
int exchange()
{
    int i, j, k, cnt = 0;
    for(i = 1; i <= N; i ++)
        if(ans[i] != i)
        {
            g[ans[i]] = g[i];
            ans[g[i]] = ans[i];
            cnt ++;
        }
    return cnt;
}
void solve()
{
    int i, j, k, start, cnt;
    for(i = 1; i <= N; i ++)
        scanf("%d", &a[i]);
    min = INF;
    for(start = 1; start <= N; start ++)
    {
        for(i = 1, j = start; i <= N; i ++, j ++)
        {
            if(j > N)
                j = 1;
            ans[i] = a[j];
            g[a[j]] = i;
        }
        cnt = exchange();
        if(cnt < min)
            min = cnt;
    }
    for(start = 1; start <= N; start ++)
    {
        for(i = 1, j = start; i <= N; i ++, j --)
        {
            if(j == 0)
                j = N;
            ans[i] = a[j];
            g[a[j]] = i;
        }
        cnt = exchange();
        if(cnt < min)
            min = cnt;
    }
    printf("%d\n", min);
}
int main()
{
    while(1)
    {
        scanf("%d", &N);
        if(!N)
            break;
        solve();
    }
    return 0;
}
