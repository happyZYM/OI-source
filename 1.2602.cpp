#include<cstdio>
typedef long long LL;
LL a,b,pow10[20]={1},f[20],cnta[20],cntb[20];
void solve(LL x,LL *cnt)
{
    LL num[20]={0},len=0;
    while(x) { num[++len]=x%10; x/=10; }
    for(int i=len;i>=1;i--)
    {
        for(int j=0;j<10;j++) cnt[j]+=f[i-1]*num[i];
        for(int j=0;j<num[i];j++) cnt[j]+=pow10[i-1];
        LL num2=0;
        for(int j=i-1;j>=1;j--) num2=num2*10+num[j];
        cnt[num[i]]+=num2+1;
        cnt[0]-=pow10[i-1];
    } 
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    scanf("%lld %lld",&a,&b);
    for(int i=1;i<15;i++)
    {
        f[i]=f[i-1]*10+pow10[i-1];
        pow10[i]=10*pow10[i-1];
    }
    solve(a-1,cnta); solve(b,cntb);
    for(int i=0;i<10;i++) printf("%lld ",cntb[i]-cnta[i]);
    return 0;
}
