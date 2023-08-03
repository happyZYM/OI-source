#include<cstdio>
#include<algorithm>
using namespace std;
int L,n,x[1000005];
void solve()
{
	int minT=0;
	for(int i=0;i<n;i++) minT=max(minT,min(x[i],L-x[i]));
	int maxT=0;
	for(int i=0;i<n;i++) maxT=max(maxT,max(x[i],L-x[i]));
	printf("%d %d\n",minT,maxT);
}
void init()
{
	scanf("%d%d",&L,&n);
	for(int i=0;i<n;i++) scanf("%d",x+i);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		init();
		solve();
	}
	return 0;
}
