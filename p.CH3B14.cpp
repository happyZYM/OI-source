//http://contest-hunter.org:83/contest/0x3B%E3%80%8C%E6%95%B0%E5%AD%A6%E7%9F%A5%E8%AF%86%E3%80%8D%E7%BB%83%E4%B9%A0/3B14%20%E6%8D%A2%E6%95%99%E5%AE%A4
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2005;
const int maxm=2005;
const int maxv=305;
const int oo=0x3f3f3f3f;
int dis[maxv][maxv];
int n,m,v,e;
int c[maxn],d[maxn];
double k[maxn];
double dp[maxn][maxm][2];
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    scanf("%d%d%d%d",&n,&m,&v,&e);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    for(int i=1;i<=n;i++) scanf("%lf",&k[i]);
    int a,b,w;
    memset(dis,oo,sizeof(dis));
    for(int i=1;i<=e;i++)
    {
        scanf("%d%d%d",&a,&b,&w);
        dis[a][b]=min(dis[a][b],w); dis[b][a]=dis[a][b];
    }
    for(int i=1;i<=v;i++) dis[i][i]=0;
    for(int k=1;k<=v;k++)
        for(int i=1;i<=v;i++)
            for(int j=1;j<=v;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j][0]=dp[i][j][1]=oo;
    dp[1][0][0]=dp[1][1][1]=0;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=m&&j<=i;j++)
        {
            dp[i][j][0]=min(dp[i-1][j][0]+dis[c[i-1]][c[i]],
                            dp[i-1][j][1]+k[i-1]*dis[d[i-1]][c[i]]
                                         +(1-k[i-1])*dis[c[i-1]][c[i]]
                        );
            if(j==0) continue;
            dp[i][j][1]=min(dp[i-1][j-1][0]+k[i]*dis[c[i-1]][d[i]]
                                           +(1-k[i])*dis[c[i-1]][c[i]],
                            dp[i-1][j-1][1]+k[i-1]*k[i]*dis[d[i-1]][d[i]]
                                           +k[i-1]*(1-k[i])*dis[d[i-1]][c[i]]
                                           +(1-k[i-1])*k[i]*dis[c[i-1]][d[i]]
                                           +(1-k[i-1])*(1-k[i])*dis[c[i-1]][c[i]]
                        );
        }
    double res=oo;
    for(int i=0;i<=m;i++) res=min(res,min(dp[n][i][0],dp[n][i][1]));
    printf("%.2lf\n",res);
    return 0;
}
