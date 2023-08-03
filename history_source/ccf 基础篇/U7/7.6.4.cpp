#include<cstdio>
#include<cstdlib>
#define MAXN 550
#define MAX MAXN/2-1
using namespace std;
bool isp[MAXN],use[MAX+1];
int ans[MAX];
int x;
void search(int n)
{
	if(n==x) 
	{
		if(isp[ans[x-1]+ans[0]])
		{
			for(int i=0;i<x;i++) printf("%d ",ans[i]);
			exit(0);
		}
	}
	for(int i=1;i<=x;i++)
	{
		if((!use[i])&&isp[ans[n-1]+i])
		{
			use[i]=1;
			ans[n]=i;
			search(n+1);
			use[i]=0;
		}
	}
}
int main()
{
	for(int i=2;i<MAXN;i++) isp[i]=1;
	for(int i=2;i<MAXN;i++)
		if(isp[i])
			for(int j=2;j*i<MAXN;j++)
				isp[j*i]=0;
//	scanf("%d",&x);
	x=20;
	if(x&1)
	{
		printf("-1\n");
		return 0;
	}
	use[1]=1;
	ans[0]=1;
	search(1);
	return 0;
}
