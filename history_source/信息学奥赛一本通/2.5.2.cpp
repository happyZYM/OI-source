#include<cstdio>
#include<cmath>
#include<cstdlib>
int x[26];
int ans=0;
bool check(int y)
{
	for(int i=1;i<y;i++)
	    if(x[i]==x[y]||abs(i-y)==abs(x[i]-x[y])) return 0;
	return 1;
}
void print(int n)
{
	printf("No. %d\n",ans);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i]==j) printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}
}
void dfs(int y,int n)
{
	if(y>n){ans++;print(n);return;}
	for(int i=1;i<=n;i++)
	{
		x[y]=i;
		if(check(y)) dfs(y+1,n);
	}
}
int main()
{
	int n;
	n=8;
	dfs(1,n);
	return 0;
}

