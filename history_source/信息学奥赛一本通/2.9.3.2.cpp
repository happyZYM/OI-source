#include<cstdio>
#include<string.h>
char a[1010],b[1010];
int dp[1010][1010];
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int answer()
{
	int len_a=strlen(a),len_b=strlen(b);
	for(int i=1;i<=len_a;i++) dp[i][0]=i;
	for(int i=1;i<=len_b;i++) dp[0][i]=i;
	for(int i=1;i<=len_a;i++)
		for(int j=1;j<=len_b;j++)
			if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
			else 
				dp[i][j]=
				min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
	return dp[len_a][len_b];
}
int main()
{
	int n;
	scanf("%d",&n);
	int ans[n];
	for(int i=0;i<n;i++)
	{
		scanf("%s%s",a,b);
		ans[i]=answer();
	}
	for(int i=0;i<n;i++) printf("%d\n",ans[i]);
	return 0;
}
