#include<stdio.h>
#include<string.h>
int n, st[110], top, G[110][110], vis[110];
void dfs(int u)
{
    int v;
    vis[u] = 1;
    for(v = 1; v <= n; v++)
        if(G[u][v] && !vis[v])
            dfs(v);
    st[--top] = u;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    int i,j,k,m,a,b;
    while(1)
    {
        scanf("%d%d", &n, &m);
        if(n == 0)
            break;
        memset(G, 0, sizeof(G));
        for(i=0; i <m; i++)
        {
            scanf("%d%d", &a, &b);
            G[a][b] = 1;
        }
        memset(vis, 0, sizeof(vis));
        top = n;
        for(i=1; i <= n;i++)
            if(!vis[i])
                dfs(i);
        for(i=0; i <n; i++)
        {
            if(i)
                printf(" ");
            printf("%d", st[i]);
        }
        printf("\n");
    }
    return 0;
}
