#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10005;
const int maxm=1005;
const int oo=0x3f3f3f3f;
int n,m,k,past,x[maxn],y[maxn],up[maxn],down[maxn],*now,*last,dp[2][maxm],hp[maxn];
const int sz=sizeof(dp[0]);
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=k;i++)
	{
		int P,L,H; scanf("%d%d%d",&P,&L,&H);
		down[P]=L; up[P]=H; hp[P]=1;
	}
	now=dp[0]; last=dp[1];
	for(int i=1;i<=n;i++)
	{
		memset(now,0x3f,sz);
		for(int j=1;j<=m;j++)
			now[min(j+x[i],m)]=min(now[min(j+x[i],m)],min(now[j],last[j])+1);
		for(int j=1;j<=m;j++)
			if(j-y[i]>0) now[j-y[i]]=min(now[j-y[i]],last[j]);
		for(int j=1;j<=m;j++)
			if(hp[i]&&(j<=down[i]||j>=up[i])) now[j]=oo; 
		bool End=true;
		for(int j=1;j<=m;j++) if(now[j]<oo) { End=false; break; }
		if(End) { printf("0\n%d\n",past); return 0; }
		past+=hp[i];
		swap(now,last);
	}
	int res=oo;
	for(int j=1;j<=m;j++) res=min(res,last[j]);
	printf("1\n%d\n",res);
	return 0;
}
