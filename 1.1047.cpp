#include<cstdio>
#include<cstring>
bool board[10005];
int main()
{
    int L,m;
    scanf("%d%d",&L,&m);
    int a,b;
    memset(board,1,sizeof(board));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        memset(board+a,0,b-a+1);
    }
    int ans=0;
    for(int i=0;i<=L;i++) ans+=board[i];
    printf("%d\n",ans);
    return 0;
}
