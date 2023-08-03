#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=20005;
const int delta=10000;
int n,T,a[105],f[105][maxn],flg[105],c[105];
inline void add(int p,int v)
{
	for(;p<=n;p+=(p&-p)) c[p]+=v;
}
inline int ask(int p)
{
	int res=0;
	for(;p;p-=(p&-p)) res+=c[p];
	return res;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==1) { puts("1"); return 0; }
	f[1][a[1]+delta]=1; f[2][a[1]-a[2]+delta]=1;
	for(int i=3;i<=n;i++)
	{
		for(int j=a[i]-10000;j<=10000;j++) f[i][j+delta]|=f[i-1][j-a[i]+delta];
		for(int j=10000-a[i];j>=-10000;j--) f[i][j+delta]|=f[i-1][j+a[i]+delta];
	}
	if(f[n][T+delta]==0) { puts("emmm"); return 0; }
	for(int v=T+delta,i=n;i>=2;i--)
	{
		if(v+a[i]<=20000&&f[i-1][v+a[i]]) { flg[i]=-1; v+=a[i]; }
		else if(v-a[i]>=0&&f[i-1][v-a[i]]) { flg[i]=+1; v-=a[i]; }
	}
	// for(int i=2;i<=n;i++) printf("flg[%d]=%d\n",i,flg[i]);
	for(int i=2;i<=n;i++) add(i,1);
	for(int i=2;i<=n;i++)
		if(flg[i]==1)
		{
			printf("%d\n",ask(i));
			add(i,-1);
		}
	for(int i=2;i<=n;i++)
		if(flg[i]==-1)
		{
			printf("%d\n",ask(i));
			add(i,-1);
		}
	// puts("1");
	return 0;
}