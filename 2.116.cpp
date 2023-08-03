#include<cstdio>
#include<cstring>
#include<algorithm>
int n,m;
int a[15][105],dp[15][105],next[15][105],oo=1<<30;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&m,&n)==2)
	{
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		int ans=oo,first=0;
		for(int j=n-1;j>=0;j--)
			for(int i=0;i<m;i++)
			{
				if(j==n-1) dp[i][j]=a[i][j];
				else
				{
					int rows[3]={i,i-1,i+1};
					if(i==0) rows[1]=m-1;
					if(i==m-1) rows[2]=0;
					std::sort(rows,rows+3);
					dp[i][j]=oo;
					for(int k=0;k<3;k++)
					{
						int v=dp[rows[k]][j+1]+a[i][j];
						if(v<dp[i][j])
						{
							dp[i][j]=v;
							next[i][j]=rows[k];
						}
					}
				}
				if(j==0&&dp[i][j]<ans)
				{
					ans=dp[i][j];
					first=i;
				}
			}
		printf("%d",first+1);
		for(int i=next[first][0],j=1;j<n;i=next[i][j],j++)
			printf(" %d",i+1);
		printf("\n%d\n",ans);
	}
	return 0;
}
