#include<cstdio>
#include<algorithm>
using namespace std;
int n,S;
int a[100005];
void init()
{
	scanf("%d%d",&n,&S);
	for(int i=0;i<n;i++) scanf("%d",a+i);
}
void solve()
{
	int l,r,sum,res=n+1;
	l=r=sum=0;
	while(1)
	{
		while(r<n&&sum<S) sum+=a[r++];
		if(sum<S) break;
		res=min(res,r-l);
		sum-=a[l++];
	}
	if(res>n) printf("0\n");
	else printf("%d\n",res);
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n-->0)
	{
		init();
		solve();
	}
	return 0;
}
