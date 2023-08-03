#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t,ti,i,j,res;
int dp1[180*50+678+5];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int KASE,kase=0;
	scanf("%d",&KASE);
	while(KASE-->0)
	{
		memset(dp1,-1,sizeof(dp1));
		dp1[0]=0;
		res=0;
		scanf("%d%d",&n,&t);
		for(i=0;i<n;i++)
		{
			scanf("%d",&ti);
			for(j=t-1;j>=ti;j--)
			{
				dp1[j]=max(dp1[j],dp1[j-ti]+1);
				res=max(res,dp1[j]);
			}
		}
		for(i=t-1;i>=0;i--)
			if(dp1[i]==res)
			{
				printf("Case %d: %d %d\n",++kase,res+1,i+678);
				break;
			}
	}
	return 0;
}
