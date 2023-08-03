#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=100000000;
int n,m,can[13],jc[1<<12],cnt,tmp[1<<13],f[13][1<<12];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int st=0;
		for(int j=0;j<m;j++)
		{
			int x; scanf("%d",&x);
			st=(st<<1)|x;
		}
		can[i]=st;
	}
	can[0]=(1<<m)-1;
	tmp[0]=1;
	for(int i=0;i<(1<<m);i++)
	{
		if((i<<1)<(1<<m)) tmp[i<<1]=tmp[i];
		if((i&1)==0&&(i<<1)<(1<<m)) tmp[i<<1|1]=tmp[i];
	}
	for(int i=0;i<(1<<m);i++) if(tmp[i]) jc[cnt++]=i;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<cnt;j++)
		{
			int st=jc[j];
			if((st&can[i])!=st) continue;
			for(int k=0;k<cnt;k++) if((jc[k]&st)==0&&(jc[k]&can[i-1])==jc[k]) f[i][st]=(f[i][st]+f[i-1][jc[k]])%mod;
		}
	int res=0;
	for(int i=0;i<cnt;i++) res=(res+f[n][jc[i]])%mod;
	printf("%d\n",res);
	return 0;
}