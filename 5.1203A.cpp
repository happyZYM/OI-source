#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Q,n,a[205];
int check(int d)
{
	int p=0;
	for(int i=0;i<n;i++)
	{
		int t=a[i]-a[(i+d+n)%n];
		if(t!=1&&t!=1-n) return 0;
	}
	return 1;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&Q);
	while(Q-->0)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		if(check(1)||check(-1)) puts("YES");
		else puts("NO");
	}
	return 0;
}