#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=250*250+10;
const int oo=1e9;
int T,n,p,q,x,res;
int s[maxn],g[maxn],d[maxn];
int idx[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d%d%d",&n,&p,&q);
		memset(idx,0,sizeof(idx));
		for(int i=1;i<=p+1;i++) { scanf("%d",&x); idx[x]=i; }
		n=0;
		for(int i=0;i<q+1;i++)
		{
			scanf("%d",&x);
			if(idx[x]) s[n++]=idx[x];
		}
		
		fill(g+1,g+1+n,oo);
		res=0;
		for(int i=0;i<n;i++)
		{
			int k=lower_bound(g+1,g+1+n,s[i])-g;
			d[i]=k;
			g[k]=s[i];
			res=max(res,d[i]);
		}
		printf("Case %d: %d\n",kase,res);
	}
	return 0;
}
