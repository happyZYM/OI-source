#include<cstdio>
#include<cstring>
#include<algorithm>
//#include<conio.h>
using namespace std;
const int oo=1<<30;
bool has_train[201][51][2];
int t[51],dp[201][51];
int n,T,i,j,m,d,ti,kase;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		memset(has_train,0,sizeof(has_train));
		scanf("%d",&T);
		for(i=1;i<=n-1;i++) scanf("%d",&t[i]);
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&d);
			for(j=1,ti=d;j<=n&&ti<=T;ti+=t[j],j++)
				has_train[ti][j][0]=1;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&d);
			for(j=n,ti=d;j>=1&&ti<=T;ti+=t[j-1],j--)
				has_train[ti][j][1]=1;
		}
		
//		printf("right:\n");
//		printf("      sta\\time");
//		for(i=0;i<=T;i++) printf("%3d",i);
//		printf("\n");
//		for(i=1;i<=n;i++)
//		{
//			printf("      %d       ",i);
//			for(j=0;j<=T;j++) printf("%s",has_train[j][i][0]?"  *":"   ");
//			printf("\n");
//		}
//		printf("left :\n");
//		printf("      sta\\time");
//		for(i=0;i<=T;i++) printf("%3d",i);
//		printf("\n");
//		for(i=1;i<=n;i++)
//		{
//			printf("      %d       ",i);
//			for(j=0;j<=T;j++) printf("%s",has_train[j][i][1]?"  *":"   ");
//			printf("\n");
//		}
//		getch();
		
		for(i=1;i<=n-1;i++) dp[T][i]=oo;
		dp[T][n]=0;
		for(i=T-1;i>=0;i--)
			for(j=1;j<=n;j++)
			{
				dp[i][j]=dp[i+1][j]+1;
				if(j<n&&has_train[i][j][0]&&i+t[j]<=T)
					dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]); //right
				if(j>1&&has_train[i][j][1]&&i+t[j-1]<=T)
					dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]); //left
			}
		
		printf("Case Number %d: ",++kase);
		if(dp[0][1]>=oo) printf("impossible\n");
		else printf("%d\n",dp[0][1]);
//		getch();
	}
	return 0;
}
