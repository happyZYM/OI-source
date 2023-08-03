#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1005;
int T,n,p[maxn];
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T-->0)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        sort(p+1,p+n+1);
        int res=0;
        for(int i=n;i>=1;i-=2) res^=(p[i]-p[i-1]-1);
        puts(res?"Georgia will win":"Bob will win");
    }
    return 0;
}
