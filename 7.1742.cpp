#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[105],c[105],f[100005],used[100005];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
		memset(f,0,sizeof(f));
		f[0]=1;
		for(int i=1;i<=n;i++)
		{
			memset(used,0,sizeof(used));
			for(int j=a[i];j<=m;j++)
				if(!f[j]&&f[j-a[i]]&&used[j-a[i]]<c[i])
				{
					f[j]=true;
					used[j]=used[j-a[i]]+1;
				}
		}
		int res=0;
		for(int i=1;i<=m;i++) res+=f[i];
		printf("%d\n",res);
	}
	return 0;
}