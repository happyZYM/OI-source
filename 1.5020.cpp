#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
const int maxv=25005;
int T,n,a[maxn];
int vis[maxv];
int solve()
{
    int maxv=a[1];
    for(int i=2;i<=n;i++) maxv=max(maxv,a[i]);
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    for(int i=1;i<=n;i++)
        for(int k=0;k+a[i]<=maxv;k++)
            vis[k+a[i]]=min(2,vis[k+a[i]]+vis[k]);
    int res=n;
    for(int i=1;i<=n;i++) if(vis[a[i]]>=2) res--;
    return res;
}
int main()
{
    scanf("%d",&T);
    while(T-->0)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        printf("%d\n",solve());
    }
    return 0;
}
