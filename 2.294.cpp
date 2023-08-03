#include"stdio.h"
#define maxn 32000
int prime[maxn],origin[maxn];
 
int getfactor(int* prime ,int i)// 求出因数个数
{
    int sum=1,count;
    for(int j=1; j<prime[0]&&i!=1; j++)
        if(i%prime[j]==0)
        {
            count=1;
            while(i%prime[j]==0)
            {
                count++;
                i/=prime[j];
            }
            sum*=count;
        }
    return sum;
}
 
int main()
{
    /* 利用素数筛法得出32000以内所有素数 存入prime数组中 */
    for(int i=0; i<maxn; i++)
        origin[i]=1;
    for(int i=2; i<maxn; i++)
        if(origin[i])
            for(int j=2*i; j<maxn; j+=i)
                origin[j]=0;
    prime[0]=0;
    for(int i=2; i<maxn; i++)
        if(origin[i])
            prime[++prime[0]]=i; // 用prime[0]表示素数个数
 
    /* 利用getfactor函数得出因子数 ，
    若大于之前出现过的最大因子数，则存入d. */
    int t,n,l,h,p,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&h);
        d=0;
        for(int i=l; i<=h; i++)
        {
            n=getfactor(prime,i);
            if(n>d)
            {
                d=n;
                p=i;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,h,p,d);
    }
    return 0;
}
