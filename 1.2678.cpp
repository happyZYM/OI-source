#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=50005;
int L,n,m,d[maxn];
bool check(int len)
{
	int cnt=0,last=0;
	for(int i=1;i<=n;i++)
		if(d[i]-last>=len) last=d[i];
		else cnt++;
	return cnt<=m&&L-last>=len;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&L,&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	int l=1,r=L,res=L;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1,res=mid;
		else r=mid-1;
	}
	printf("%d\n",res);
	return 0;
}
/*
65343245 0 0
*/
