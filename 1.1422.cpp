#include<cstdio>
int main()
{
    double n;
    scanf("%lf",&n);
    double res;
    if(n<=150) res=n*0.4463;
    else if(n<=400) res=150*0.4463+(n-150)*0.4663;
    else res=150*0.4463+250*0.4663+(n-400)*0.5663;
    printf("%.1lf\n",res);
    return 0;
}
//267
