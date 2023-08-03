#include<cstdio>
typedef long long LL;
LL val[1001][1001];
LL C(LL n,LL m)
{
	LL &res=val[n][m];
    if(res) return res;
    if(m>n) return 0;
    if(m==1) return res=n;
    if(m==0||m==n) return res=1;
    return res=C(n-1,m)+C(n-1,m-1);
}
int cnt[10],v[55],n,tot;
LL res;
char c;
LL cal()
{
    LL res=1; int m=n;
    for(int i=0;i<=9;i++) if(cnt[i]) { res*=C(m,cnt[i]); m-=cnt[i]; }
    return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    while(scanf("%c",&c)==1) if('0'<=c&&c<='9') { v[++n]=c-48; cnt[v[n]]++; }
    tot=n;
    for(int i=1;i<=tot;i++)
	{
	    n--;
	    for(int j=0;j<v[i];j++) if(cnt[j]) { cnt[j]--; res+=cal(); cnt[j]++; }
	    cnt[v[i]]--;
	}
    printf("%lld",res);
    return 0;
}
