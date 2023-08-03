#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=35;
typedef long long LL;
const LL oo=0x3f3f3f3f3f3f3f3fll;
int T,L,a,b,c;
LL f[maxn][maxn][maxn][maxn][2];
inline void CM(LL &a,const LL &b) { a=min(a,b); }
int read()
{
	int x; scanf("%d",&x);
	int stk[80],cnt=0;
	while(x) stk[cnt++]=x&1,x>>=1;
	L=max(L,cnt);
	x=0;
	for(int i=0;i<cnt;i++) x+=stk[i];
	return x;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&T);
	memset(f,0x3f,sizeof(f));
	f[0][0][0][0][0]=0;
	for(int i=0;i<32;i++)
		for(int a=0;a<32;a++)
			for(int b=0;b<32;b++)
				for(int c=0;c<32;c++)
				{
					LL v=f[i][a][b][c][0];
					CM(f[i+1][a][b][c][0],v);
					CM(f[i+1][a+1][b][c+1][0],v+(1<<i));
					CM(f[i+1][a][b+1][c+1][0],v+(1<<i));
					CM(f[i+1][a+1][b+1][c][1],v+(1<<i+1));
					v=f[i][a][b][c][1];
					CM(f[i+1][a][b][c+1][0],v);
					CM(f[i+1][a+1][b][c][1],v+(1<<i));
					CM(f[i+1][a][b+1][c][1],v+(1<<i));
					CM(f[i+1][a+1][b+1][c+1][1],v+(1<<i+1));
				}
	while(T-->0)
	{
		L=0;
		a=read(); b=read(); c=read();
		printf("%lld\n",f[L][a][b][c][0]==oo?-1:f[L][a][b][c][0]);
	}
	return 0;
}