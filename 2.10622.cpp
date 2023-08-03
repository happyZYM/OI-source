#include<cstdio>
#include<cmath>
typedef long long LL;
inline LL quickpow(LL x,LL n)
{
    LL result=1;
    for(;n;n>>=1)
	{
        if(n&1)
            result*=x;
        x*=x;
    }
    return result;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    LL x,px,ans;
    while(~scanf("%lld",&x)&&x)
	{
        bool flag=false;
        px=x<0?-x:x;
        for(int i=2;i<=floor(sqrt(px))&&!flag;i++)
		{
            for(int j=2;;j++)
			{
                LL t=quickpow(i,j);
                if(t>px)
                    break;
                if(t==px&&(x>0||(x<0&&(j%2==1))))
				{
                    flag=true;
                    ans=j;
                    break;
                }
            }
        }
        printf("%lld\n",flag?ans:1);
    }
    return 0;
}
