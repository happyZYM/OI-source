#include<cstdio>
#include<cmath>
int x[26];
int ans=-1;
int chuan[92];
bool check(int y)
{
	for(int i=1;i<y;i++)
	    if(x[i]==x[y]||abs(i-y)==abs(x[i]-x[y])) return 0;
	return 1;
}
void print(int n)
{
	chuan[ans]=x[0];
	for(int i=1;i<=8;i++) chuan[ans]=chuan[ans]*10+x[i];
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
	scanf("%d",&n);
	int sr[n];
	for(int i=0;i<n;i++) scanf("%d",sr+i);
	for(int i=0;i<n;i++) printf("%d\n",chuan[sr[i]-1]);
	return 0;
}

