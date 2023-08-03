#include<cstdio>
#include<cmath>
int main()
{
    double s,x,tEnter,tExit;
    scanf("%lf%lf",&s,&x);
    tEnter=log(1-0.02*(s-x)/7)/log(0.98);
    tExit=log(1-0.02*(s+x)/7)/log(0.98);
    printf("%c",tExit-tEnter>=1?'y':'n');
    return 0;
}
