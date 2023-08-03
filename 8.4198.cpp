#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
struct DT { LL w; int d; };
inline bool operator<(const DT &a,const DT &b) { return !(a.w<b.w||(a.w==b.w&&a.d<b.d)); }
int n,k,mxl; LL x,tot;
priority_queue<DT> Q;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) { scanf("%lld",&x); Q.push((DT){x,0}); }
	if((n-1)%(k-1)) for(int i=0;i<k-1-(n-1)%(k-1);i++) Q.push((DT){0LL,0});
	while(Q.size()>=k)
	{
		LL a=0; int nl=0;
		for(int i=0;i<k;i++)
		{
			DT u=Q.top(); Q.pop();
			nl=max(nl,u.d+1); a+=u.w;
		}
		mxl=max(mxl,nl);
		tot+=a;
		Q.push((DT){a,nl});
	}
	printf("%lld\n%d\n",tot,mxl);
	return 0;
}
