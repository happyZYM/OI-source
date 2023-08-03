#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,res,a[105];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1,j;i<=n;i++)
		{
			scanf("%d",&j);
			a[i]^=j;
			a[i]|=1<<i; //a[i][i]=1;
		}
		int x,y;
		while(scanf("%d%d",&x,&y)==2&&x&&y) a[y]|=1<<x;//a[y][x]=1;
		int res=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++) if(a[j]>a[i]) swap(a[j],a[i]);
			if(a[i]==0) { res=1<<(n-i+1); break; }
			if(a[i]==1) { res=0; break; }
			for(int k=n;k;k--)
				if(a[i]>>k&1)
				{
					for(int j=1;j<=n;j++)
						if(i!=j&&(a[j]>>k&1)) a[j]^=a[i];
					break;
				}
		}
		if(res==0) puts("Oh,it's impossible~!!");
		else printf("%d\n",res);
	}
	return 0;
}
