#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5005;
int n,rlen,rtot,a[maxn],len[maxn],tot[maxn],useful[maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) len[i]=tot[i]=useful[i]=1;
		rlen=rtot=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(a[j]>a[i]&&useful[j])
				{
					if(len[i]==len[j]+1) tot[i]+=tot[j];
					else if(len[i]<len[j]+1)
					{
						tot[i]=tot[j];
						len[i]=len[j]+1;
					}
				}
				else if(a[i]==a[j]) { if(len[i]==1) useful[i]=0; break; }
			}
			rlen=max(rlen,len[i]);
		}
		for(int i=1;i<=n;i++) if(len[i]==rlen) rtot+=tot[i];
		printf("%d %d\n",rlen,rtot);
	}
	return 0;
}