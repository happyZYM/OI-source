#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[4005],b[4005],c[4005],d[4005];
int tmp[4000*4000+1],cnt;
void solve()
{
	int i,j;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j) tmp[cnt++]=a[i]+b[j];
	sort(tmp,tmp+cnt);
	long long res=0;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			res+=upper_bound(tmp,tmp+cnt,-c[i]-d[j])-lower_bound(tmp,tmp+cnt,-c[i]-d[j]);
	printf("%lld\n",res);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		cnt=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
		solve();
		if(t) printf("\n");
	}
	return 0;
}
