#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[100005];
bool solve(int maxn)
{
	int sum=0,cnt=1,res=0;
	for(int i=0;i<n;i++)
		if(sum+a[i]>maxn)
		{
			cnt++;
			res=max(res,sum);
			sum=a[i];
		}
		else sum+=a[i];
	if(cnt>m) return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	int l=0,r=0,mid;//(l,r]
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		r+=a[i];
		l=max(l,a[i]);
	}
	while(l<r)
	{
		mid=(l+r)>>1;
		if(solve(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}
