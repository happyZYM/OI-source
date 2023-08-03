#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=11380;
int L1,L2,L3,D,f[31][11][11][11];
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	f[0][0][0][0]=1;
	scanf("%d%d%d%d",&L1,&L2,&L3,&D);
	FOR(d,1,D) FOR(i,0,L1) FOR(j,0,L2) FOR(k,0,L3)
	{
		int &now=f[d][i][j][k];
		if(i+j+k==0) { now=1; continue; }
		FOR(a,0,i-1) FOR(b,0,j) FOR(c,0,k) now=(now+f[d-1][a][b][c]*f[d][i-a-1][j-b][k-c])%mod;
		FOR(b,0,j-1) FOR(c,0,k) now=(now+f[d-1][0][b][c]*f[d][i][j-b-1][k-c])%mod;
		FOR(c,0,k-1) now=(now+f[d-1][0][0][c]*f[d][i][j][k-c-1])%mod;
	}
	printf("%d\n",(f[D][L1][L2][L3]-(D?f[D-1][L1][L2][L3]:0)+mod)%mod);
	return 0;
}