#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned long long ULL;
int n,m,pcnt[1<<9];
ULL f[10][1<<9][82],res=0;
vector<int> nxt[1<<9];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	f[0][0][0]=1;
	for(int st=0;st<(1<<n);st++)
		for(int i=0;i<(1<<n);i++) if((st&i)==0&&(st&(i<<1))==0&&(st&(i>>1))==0&&(i&(i<<1))==0) nxt[st].push_back(i);
	for(int i=1;i<(1<<n);i++) pcnt[i]=pcnt[i>>1]+(i&1);
	for(int i=0;i<n;i++) for(int st=0;st<(1<<n);st++) for(int j=0;j<=m&&j<=n*i;j++) if(f[i][st][j])
	{
		ULL v=f[i][st][j];
		for(int k=0;k<nxt[st].size();k++) if(j+pcnt[nxt[st][k]]<=m) f[i+1][nxt[st][k]][j+pcnt[nxt[st][k]]]+=v;
	}
	for(int st=0;st<(1<<n);st++) res+=f[n][st][m];
	printf("%llu\n",res);
	return 0;
}