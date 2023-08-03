#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100005;
LL n,a[maxn],w[maxn],s[maxn],p,res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n),n!=0)
	{
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		a[n+1]=p=res=0;
		for(int i=1;i<=n+1;i++)
		{
			if(a[i]>s[p]) { s[++p]=a[i]; w[p]=1; }
			else
			{
				LL wid=0;
				while(s[p]>a[i])
				{
					wid+=w[p];
					res=max(res,wid*s[p]);
					p--;
				}
				s[++p]=a[i]; w[p]=wid+1;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
