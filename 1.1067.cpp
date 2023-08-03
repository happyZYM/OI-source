#include<cstdio>
int n,x;
bool first=true;
int main()
{
    scanf("%d",&n);
    for(int i=n;i>=0;i--)
    {
        scanf("%d",&x);
        if(x==0) continue;
        if(x>0&&!first) printf("+");
        if(x<0) printf("-"),x=-x;
        if(i==0) printf("%d",x);
        else
        {
            if(x!=1) printf("%d",x);
            if(i==1) printf("x");
            else printf("x^%d",i);
        }
        first=false;
    }
    printf("\n");
    return 0;
}
