#include<cstdio>
typedef long long LL;
int main()
{
    LL L=1,R,M,n,a;
    scanf("%lld",&n);
    R=n;
    while(L<R)
    {
        M=(L+R)/2;
        if(M*(M+1)/2<n) L=M+1;
        else R=M;
    }
    a=n-L*(L-1)/2;
    if(L%2==0) printf("%lld/%lld\n",a,L+1-a);
    else printf("%lld/%lld\n",L+1-a,a);
    return 0;
}
