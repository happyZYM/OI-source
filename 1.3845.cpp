#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int oo=0x3f3f3f3f;
const int maxn=1005;
struct Node { int a,b; };
inline bool operator<(const Node &a,const Node &b) { return a.a<b.a||(a.a==b.a&&a.b<b.b); }
int T,n,dp[maxn];
Node p[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int x,y; scanf("%d-%d",&x,&y);
			p[i].a=min(x,y);
			p[i].b=max(x,y);
		}
		sort(p,p+n);
		memset(dp,oo,sizeof(dp));
		for(int i=n-1;i>=0;i--) *lower_bound(dp,dp+n+1,p[i].b)=p[i].b;
		printf("%d\n",lower_bound(dp,dp+n+1,oo)-dp);
	}
	return 0;
}
