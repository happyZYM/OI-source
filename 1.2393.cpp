#include<cstdio>
long double res,t;
int main()
{
    while(scanf("%Lf",&t)==1) res+=t*1000000;
    printf("%.5Lf\n",res/1000000);
    return 0;
}
