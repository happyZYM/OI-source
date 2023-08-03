#include<cstdio>
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;++i)
        if(n%i==0)
        {
            printf("%d",n/i);
            return 0;
        }
    return 0;
}
