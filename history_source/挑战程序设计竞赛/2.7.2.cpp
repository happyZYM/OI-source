#include<cstdio>
#include<algorithm>
using namespace std;
int n,M[45][45],a[45];
void init()
{
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&M[i][j]);
}
void solve()
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		a[i]=-1;
		for(int j=0;j<n;j++)
			if(M[i][j]==1) a[i]=j;
	}
	for(int i=0;i<n;i++)
	{
		int pos=-1;
		for(int j=i;j<n;j++)
			if(a[j]<=i)
			{
				pos=j;
				break;
			}
		for(int j=pos;j>i;j--)
		{
			swap(a[j],a[j-1]);
			res++;
		}
	}
	printf("%d\n",res);
}
int main()
{
	init();
	solve();
	return 0;
}
