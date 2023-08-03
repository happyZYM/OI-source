#include<cstdio>
int n;
int main()
{
    int n,res=0;
    scanf("%d",&n);
    if(n<0)
    {
        printf("-");
        n=-n;
    }
    while(n>0)
    {
        res=res*10+n%10;
        n/=10;
    }
    printf("%d\n",res);
    return 0;
}
