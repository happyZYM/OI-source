#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
double l[10005];
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%lf",l+i);
}
bool c(double len)
{
	int cnt=0;
	for(int i=0;i<n;i++)
		cnt+=l[i]/len;
	return (cnt>=k);
}
void solve()
{
	double l=0,r=100000,mid;
	while(r-l>0.001)
	{
		mid=(l+r)/2;
		if(c(mid)) l=mid;
		else r=mid;
	}
	printf("%.2lf\n",l);
}
int main()
{
	init();
	solve();
	return 0;
}
/*
4
11
8.02 7.43 4.57 5.39
*/
