#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000010;
int a[N],T;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		int w,n; 
		scanf("%d%d",&n,&w);
		for(int i=0;i<n;i++) scanf("%d",a+i);
		sort(a,a+n);
		int l=0,r=n-1,ans=0;
		while(l<=r)
		{
			if(a[r]+a[l]<=w) l++;
			r--; 
			ans++;
		}
		printf("%d\n",ans);
		if(T) printf("\n");
	}
	return 0;
}
