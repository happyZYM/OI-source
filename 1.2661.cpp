#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200005;
int n,res=1e9+7,T[maxn],dfn[maxn],vis[maxn],cnt;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&T[i]);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
		{
			memset(vis,0,sizeof(vis));
			int x=i;
			while(!dfn[x])
			{
				dfn[x]=++cnt; vis[x]=true;
				x=T[x];
			}
			if(vis[x]) res=min(res,cnt+1-dfn[x]);
		}
	printf("%d\n",res);
	return 0;
}
