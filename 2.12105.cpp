#include<cstdio>
using namespace std;
const int maxn=105;
const int maxm=3005;
const int needs[]={6,2,5,5,4,5,6,3,7,6};
int n,m,kase;
int dp[maxn][maxm];
int p[maxn][maxm];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		scanf("%d",&m);
		printf("Case %d: ",++kase);
		for(int i=0;i<=n;i++)
			for(int j=0;j<m;j++)
			{
				int &ans=dp[i][j];
				ans=p[i][j]=-1;//init
				if(!j) ans=0;
				for(int d=9;d>=0;d--)
					if(i>=needs[d])
					{
						int t=dp[i-needs[d]][(j*10+d)%m];
						if(t>=0&&t+1>ans)
						{
							ans=t+1;
							p[i][j]=d;
						}
					}
			}
		if(p[n][0]==-1) printf("-1\n");
		else
		{
			int i=n,j=0;
			for(int d=p[i][j];d>=0;d=p[i][j])
			{
				printf("%d",d);
				i-=needs[d];
				j=(j*10+d)%m;
			}
			printf("\n");
		}
	}
	return 0;
}
