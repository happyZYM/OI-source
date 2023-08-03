#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=105;
const int oo=1<<29;
int m[maxn][maxn];
int a,b,n,kase,sum,cnt,i,j,k;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    while(scanf("%d%d",&a,&b)==2&&!(a==0&&b==0))
	{
        n=-1;
        for(i=0;i<maxn;i++)
            for(j=0;j<maxn;j++)
                m[i][j]=(i==j?0:oo);
        do
		{
            m[a][b]=1;
            n=max(max(a,b),n);
        }
		while(scanf("%d%d",&a,&b)==2&&!(a==0&&b==0));
        n++;
        for(k=1;k<n;k++)
            for(i=1;i<n;i++)
                for(j=1;j<n;j++)
                	m[i][j]=min(m[i][j],m[i][k]+m[k][j]);
        sum=cnt=0;
        for(i=1;i<n;i++)
            for(j=1;j<n;j++)
                if(m[i][j]<oo&&m[i][j])
				{
                    cnt++;
                    sum+=m[i][j];
                }
        printf("Case %d: ",++kase);
        printf("average length between pages = %.3lf clicks\n"
			,(double)sum/cnt);
    }
    return 0;
}
