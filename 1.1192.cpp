// luogu-judger-enable-o2
#include<cstdio>
const int mod=100003;
int f[100007],n,k;
int main()
{
    scanf("%d%d",&n,&k);
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k&&j<=i;j++) f[i]+=f[i-j];
        f[i]=f[i]%mod;
    }
    printf("%d",f[n]);
    return 0;
}
