#include<cstdio>
int n,k;
int a[1000005];
void solve()
{
	int l=0,r=n-1,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]<k) l=mid+1;
		else r=mid;
	}
	if(a[l]>=k) printf("%d\n",l);
	else printf("-1");
}
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	scanf("%d",&k);
}
int main()
{
	init();
	solve();
	return 0;
}
/*
5
2 3 3 5 6
3
*/
