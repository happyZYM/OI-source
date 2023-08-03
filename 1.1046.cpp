#include<cstdio>
int a[11];
int h;
int main()
{
    for(int i=0;i<10;i++) scanf("%d",a+i);
    scanf("%d",&h);
    h+=30;
    int res=0;
    for(int i=0;i<10;i++)
        if(h>=a[i]) res++;
    printf("%d\n",res);
    return 0;
}
