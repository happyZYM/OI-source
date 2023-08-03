#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x[100005];
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",x+i);
}
bool c(int d)
{
	int last=0,crt;
	for(int i=1;i<m;i++)
	{
		crt=last+1;
		while(crt<n&&x[crt]-x[last]<d) crt++;
		if(crt==n) return 0;
		last=crt;
	}
	return 1;
}
void solve()
{
	sort(x,x+n);
	int l=0,r=1<<30,mid;
	while(r-l>1)
	{
		mid=(l+r)/2;
		if(c(mid)) l=mid;
		else r=mid;
	}
	printf("%d\n",l);
}
int main()
{
	init();
	solve();
	return 0;
}
/*
5
3
1 2 8 4 9
*/
