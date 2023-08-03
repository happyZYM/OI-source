#include<cstdio>
#include<cstring>
const int len=3005;
int a,b,num[len],yu[len];
int main()
{
    while(scanf("%d%d",&a,&b)==2)
    {
        memset(num,0,sizeof(num));
        memset(yu,0,sizeof(yu));
        num[0]=a/b;
        yu[0]=a%b;
        num[1]=yu[0]*10/b;
        yu[1]=yu[0]*10%b;
        int n=0,m=0;
        for(int i=2;;i++)
        {
            num[i]=yu[i-1]*10/b;
            yu[i]=yu[i-1]*10%b;
            for(int k=1;k<i;k++)
                if(num[i]==num[k]&&yu[i]==yu[k]) {m=i;n=k;break;}
            if(n) break;
        }
        printf("%d/%d = %d.",a,b,num[0]);
        for(int i=1;i<n&&i<=50;i++)
            printf("%d",num[i]);
        printf("(");
        for(int j=n;j<m&&j<=50;j++)
            printf("%d",num[j]);
        if(m>50) printf("...");
        printf(")\n   %d = number of digits in repeating cycle\n\n",m-n);
    }
    return 0;
}
