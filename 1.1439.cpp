#include<cstdio>
#include<algorithm>
using namespace std; 
const int maxn=100005;
const int oo=1e9+7;
int n,x;
int idx[maxn],dp[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&x),idx[x]=i+1;
	fill(dp,dp+n+2,oo);
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x); x=idx[x];
		*lower_bound(dp,dp+n+2,x)=x;
	}
	printf("%d\n",lower_bound(dp,dp+n+2,oo)-dp-1);
	return 0;
}
/*
5 
3 2 1 4 5
1 2 3 4 5

3 2 1 4 5
*/
