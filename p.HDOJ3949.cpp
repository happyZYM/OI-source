//http://acm.hdu.edu.cn/showproblem.php?pid=3949
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
unsigned long long a[10005];
int T,n,m,t;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%I64u",&a[i]);
		bool flg=0;
		t=n;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				if(a[j]>a[i]) swap(a[i],a[j]);
			if(a[i]==0) { flg=1; t=i-1; break; }
			for(int k=63;k>=0;k--)
				if(a[i]>>k&1)
				{
					for(int j=1;j<=n;j++)
						if(i!=j&&(a[j]>>k&1)) a[j]^=a[i];
					break;
				}
		}
		scanf("%d",&m);
		printf("Case #%d:\n",kase);
		while(m-->0)
		{
			unsigned long long k,res=0;
			scanf("%I64u",&k);
			if(flg) k--;
			if(k>= (1llu<<t) ) puts("-1");
			else
			{
				for(int i=t-1;i>=0;i--)
					if(k>>i&1) res^=a[t-i];
				printf("%I64u\n",res);
			}
		}
	}
	return 0;
}
