#include<cstdio>
const int maxsize=100005;
int k,n,m,p;
long long inv_fac[maxsize],fac[maxsize];
long long lucas(int x,int y)
{
    if(x<y) return 0;
    else if(x<p) return fac[x]*inv_fac[y]*inv_fac[x-y]%p;
    else return lucas(x/p,y/p)*lucas(x%p,y%p)%p;
}
int main()
{
    scanf("%d",&k);
    while(k-->0)
    {
        scanf("%d%d%d",&n,&m,&p);
        inv_fac[0]=inv_fac[1]=fac[0]=fac[1]=1;
        for(int i=2;i<=n+m;i++) fac[i]=fac[i-1]*i%p;
        for(int i=2;i<=n+m;i++) inv_fac[i]=(p-p/i)*inv_fac[p%i]%p;
        for(int i=2;i<=n+m;i++) inv_fac[i]=inv_fac[i-1]*inv_fac[i]%p;
        printf("%lld\n",lucas(n+m,m));
    }
    return 0;
}
