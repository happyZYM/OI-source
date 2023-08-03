#include<cstdio>
#include<cmath>
int main()
{
    int n,m,a;
    scanf("%d%d%d",&n,&m,&a);
    printf("%lld\n",(long long)(ceil((double)n/a)*ceil((double)m/a)));
    return 0;
}
