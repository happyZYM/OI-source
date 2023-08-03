#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
int n,m,o,a[maxn],b[maxn];
int mxv[1005],mem[2][1005];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&o);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	if(m>=o) { puts("0"); return 0; }
	memset(mxv,-1,sizeof(mxv));
	mxv[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=o;j++)
			if(j-a[i]>=0&&mxv[j-a[i]]>-1)
				mxv[j]=max(mxv[j],mxv[j-a[i]]+b[i]);
	memset(mem,-1,sizeof(mem));
	int *now=mem[0],*nxt=mem[1];
	now[m]=0;
	for(int i=0;i<=1000;i++)
	{
		if(now[o]!=-1) { printf("%d\n",i); return 0; }
		for(int j=0;j<=o;j++)
		{
			if(now[j]==-1) continue;
			for(int k=0;k<=j;k++)
			{
				if(j-k+mxv[k]+now[j]>=o) { printf("%d\n",i+1); return 0; }
				nxt[j-k+mxv[k]+now[j]]=max(nxt[j-k+mxv[k]+now[j]],mxv[k]+now[j]);
			}
		}
		swap(now,nxt);
		memset(nxt,-1,4020);
	}
	return 0;
}
