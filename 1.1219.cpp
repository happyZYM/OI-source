#include<cstdio>
#include<cstring>
int n,cnt;
int res[20];
void dfs(int step,int a,int b,int c)
{
	if(step>=n)
	{
		if(cnt++<3)
		{
			printf("%d",res[0]);
			for(int i=1;i<n;i++) printf(" %d",res[i]);
			printf("\n");
		}
		return;
	}
	int cant=a|b|c;
	for(int i=1;i<=n;i++)
		if(!(cant&(1<<i)))
		{
			res[step]=i;
			dfs(step+1,a|(1<<i),(b|(1<<i))<<1,(c|(1<<i))>>1);
		}
}
int main()
{
	scanf("%d",&n);
	dfs(0,0,0,0);
	printf("%d\n",cnt);
	return 0;
}
