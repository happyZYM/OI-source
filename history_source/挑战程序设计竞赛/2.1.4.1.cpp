#include<cstdio>
int a[22],n,k;
bool dfs(int i,int sum)
{
	if(i==n) return sum==k;
	if(dfs(i+1,sum)) return 1;
	if(dfs(i+1,sum+a[i])) return 1;
	return 0;
}
void init()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",a+i);
	scanf("%d",&k);
}
void solve()
{
	if(dfs(0,0)) printf("Yes\n");
	else printf("No\n");
}
int main()
{
	init();
	solve();
	return 0;
}
