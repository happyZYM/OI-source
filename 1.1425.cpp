#include<cstdio>
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int f=(a-c-1)*60+b+60-d;
    printf("%d %d\n",-f/60,-f%60);
    return 0;
}
//12 50 19 10
