#include<cstdio>
#include<algorithm>
using namespace std;
int r,n,x[1005];
void solve()
{
	sort(x,x+n);
	static int i,ans,s,p;
	i=ans=0;
	while(i<n)
	{
		s=x[i++];
		while(i<n&&x[i]<=s+r) i++;
		p=x[i-1];
		while(i<n&&x[i]<=p+r) i++;
		ans++;
	}
	printf("%d\n",ans);
}
void init()
{
	scanf("%d%d",&r,&n);
	if(r==-1&&n==-1) exit(0);
	static int i;
	for(i=0;i<n;i++) scanf("%d",x+i);
}
int main()
{
	while(true)
	{
		init();
		solve();
	}
	return 0;
}
