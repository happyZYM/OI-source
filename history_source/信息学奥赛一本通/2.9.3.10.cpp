#include <bits/stdc++.h>
using namespace std;
const int maxn=510;
int la,lb,a[maxn],b[maxn];
struct node
{
	int len;
	vector<int> iv;
};
node dp[maxn],cur;
int main()
{
	scanf("%d",&la);
	int i,j;
	for(i=0;i<la;i++) scanf("%d",&a[i]);
	scanf("%d",&lb);
	for(i=0;i<lb;i++) scanf("%d",&b[i]);
	for(i=0;i<maxn;i++) dp[i].len=0;
	for(i=0;i<lb;i++)
	{
		cur.len=0;
		cur.iv.clear();
		for(j=0;j<la;j++)
		{
			if(b[i]>a[j]&&dp[j].len>cur.len) cur=dp[j];
			if(b[i]==a[j])
			{
				dp[j]=cur;
				dp[j].len++;
				dp[j].iv.push_back(a[j]);
			}
		}
	}
	int p=0;
	for(i=1;i<la;i++) if(dp[p].len<dp[i].len) p=i;
	printf("%d\n",dp[p].len);
	if(dp[p].iv.size())
	{
		printf("%d",dp[p].iv[0]);
		for(i=1;i<dp[p].iv.size();i++)
			printf(" %d",dp[p].iv[i]);
	}
	printf("\n");
	return 0;
}
/*
5
1 4 2 5 -12
4
-12 1 2 4
*/
