#include<cstdio>
int n,a,b,c,d,e,res;
int main()
{
    scanf("%d",&n);
    while(n-->0)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        if(a+b+c+d+e<20) res++;
    }
    printf("%d\n",res);
    return 0;
}
