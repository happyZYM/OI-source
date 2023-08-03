#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5005;
int n,rlen=1,tot,a[maxn],f[maxn],cnt[maxn],useful[maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) f[i]=cnt[i]=useful[i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
			if(a[j]>a[i]&&useful[j])
			{
				if(f[j]+1==f[i]) cnt[i]+=cnt[j];
				else if(f[j]+1>f[i]) { f[i]=f[j]+1; cnt[i]=cnt[j]; }
			}
			else if(a[j]==a[i]) { if(f[i]==1) useful[i]=0; break; }
		rlen=max(rlen,f[i]);
	}
	for(int i=1;i<=n;i++) if(rlen==f[i]) tot+=cnt[i];
	printf("%d %d\n",rlen,tot);
	return 0;
}