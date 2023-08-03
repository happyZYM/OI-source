#include<cstdio>
typedef long long ll;
const int maxp=20000530;
int n,p;
int res[maxp];
inline void write(int x)
{
    static char buf[25];
    int cnt=0;
    while(x>0) buf[cnt++]=x%10,x/=10;
    while(cnt>0) putchar(buf[--cnt]+'0');
    putchar('\n');
}
int main()
{
    scanf("%d%d",&n,&p);
    res[1]=1;
    write(1);
    for(int i=2;i<=n;i++)
    {
        //inv[i]=(ll)(p-p/i)*inv[p%i]%p;
        res[i]=(ll)(p-p/i)*res[p%i]%p;
        write(res[i]);
    }
    return 0;
}
