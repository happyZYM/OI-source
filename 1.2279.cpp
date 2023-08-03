#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1005;
int n,f[maxn],d[maxn],p[maxn],mark[maxn],res,ok[maxn],mark2[maxn];
inline bool cmp(int a,int b) { return d[a]>d[b]; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	f[1]=1; d[1]=1; p[1]=1;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&f[i]);
		d[i]=d[f[i]]+1;
		p[i]=i;
	}
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int u=p[i];
		if(mark[u]||mark[f[u]]||mark[f[f[u]]]||ok[u]||mark2[f[u]]) { ok[u]=true; continue; }
		int v=f[f[u]];
		mark[v]=true;
		ok[u]=ok[f[u]]=ok[v]=ok[f[v]]=ok[f[f[v]]]=true;
		mark2[f[v]]=true;
		res++;
	}
	printf("%d\n",res);
	return 0;
}
