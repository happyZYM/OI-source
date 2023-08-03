#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,w[10005],v[10005];
double y[10005];
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d%d",w+i,v+i);
}
bool C(double x)
{
	for(int i=0;i<n;i++) y[i]=v[i]-x*w[i];
	sort(y,y+n);
	double sum=0;
	for(int i=0;i<k;i++) sum+=y[n-i-1];
	return sum>=0;
}
void solve()
{
	double l=0,r=1000010,mid;
	for(int i=0;i<100;i++)
	{
		mid=(l+r)/2;
		if(C(mid)) l=mid;
		else r=mid;
	}
	printf("%.2f\n",r);
}
int main()
{
	init();
	solve();
	return 0;
}
/*
3 2
2 2
5 3
2 1
*/
