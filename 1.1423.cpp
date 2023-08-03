#include<cstdio>
int main()
{
    int cnt=0;
    double step=2.0,in;
    scanf("%lf",&in);
    while(in>0)
    {
        cnt++;
        in-=step;
        step*=0.98;
    }
    printf("%d\n",cnt);
    return 0;
}
