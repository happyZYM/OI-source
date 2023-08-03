#include<cstdio>
int n,cnt=1,i,f[1010];
int main()
{
    scanf("%d",&n);
    f[0]=f[1]=1;
    for(i=2;i<=n;i++)
        if(i&1) f[i]=f[i-1];
        else f[i]=f[i-1]+f[i/2];
    printf("%d\n",f[n]);
    return 0;
}
