#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
int n,v1,w1,v2,w2,v3,w3;
int main()
{
    scanf("%d%d%d%d%d%d%d",&n,&v1,&w1,&v2,&w2,&v3,&w3);
    int res;
    res=(n%v1==0?n/v1*w1:(n/v1+1)*w1);
    res=min(res,(n%v2==0?n/v2*w2:(n/v2+1)*w2));
    res=min(res,(n%v3==0?n/v3*w3:(n/v3+1)*w3));
    printf("%d\n",res);
    return 0;
}
