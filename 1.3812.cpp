#include<cstdio>
using namespace std;
typedef long long LL;
const int maxn=51;
int n;
LL ans,a[maxn],p[101];
void cal(LL x)
{
	for(int i=62;i>=0;i--)
	{
		if(!(x>>i)) continue;
		if(!p[i])
		{
			p[i]=x;
			break;
		}
		x^=p[i];
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),cal(a[i]);
	for(int i=62;i>=0;i--)
		if((ans^p[i])>ans)
			ans^=p[i];
	printf("%lld\n",ans);
	return 0;
}
