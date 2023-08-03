#include<cstdio>
#include<algorithm>
using namespace std;
inline bool cmp(long long a,long long b)
{
	return a>b;
}
long long v1[805],v2[805],n,ans;
int main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;i++) scanf("%lld",v1+i);
	for(int i=0;i<n;i++) scanf("%lld",v2+i);
	sort(v1,v1+n);
	sort(v2,v2+n,cmp);
	for(int i=0;i<n;i++) ans+=v1[i]*v2[i];
//	for(int i=0;i<n;i++) printf("%lld ",v1[i]);
//	printf("\n");
//	for(int i=0;i<n;i++) printf("%lld ",v2[i]);
//	printf("\n");
	printf("%lld\n",ans);
	return 0;
}
/*
3
1 3 -5
-2 4 1
*/
